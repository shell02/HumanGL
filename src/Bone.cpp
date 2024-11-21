#include "Bone.hpp"

std::vector<float> cubeVertices({
    0.5f, 0.5f, 0.5f,
    0.5f, 0.5f, -0.5f,
    -0.5f, 0.5f, -0.5f,
    -0.5f, 0.5f, 0.5f,
    0.5f, -0.5f, 0.5f,
    0.5f, -0.5f, -0.5f,
    -0.5f, -0.5f, -0.5f,
    -0.5f, -0.5f, 0.5f
});

std::vector<int> cubeIndices({
	0, 1, 2,
	0, 2, 3,
	0, 4, 5,
	0, 5, 1,
	1, 5, 6,
	1, 6, 2,
	2, 6, 7,
	2, 7, 3,
	3, 7, 4,
	3, 4, 0,
	4, 5, 6,
	4, 6, 7
});

Bone::Bone(std::string name) : vertices(cubeVertices), indices(cubeIndices), name(name) {
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(int), indices.data(), GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	rotation = Quaternion().toMatrix();
	scale = Matrix4(1.0f);
	baseScale = Matrix4(1.0f);
	translation = Matrix4(1.0f);
	color = Vector3(1.0f, 1.0f, 1.0f);
	centerRot = Matrix4(1.0f);
	scaleCenterRot = Matrix4(1.0f);
	orgCenterRot = Matrix4(1.0f);

	scaleConstraintX = 0.0f;
	scaleConstraintY = 0.0f;
	scaleConstraintZ = 0.0f;
}

Bone::Bone(Bone const &src) {
	*this = src;
}

Bone::~Bone() {
	vertices.clear();
	indices.clear();
}

Bone&	Bone::operator=(Bone const &src) {
	if (this != &src) {
		clear();
		vertices = src.vertices;
		indices = src.indices;
		rotation = src.rotation;
		scale = src.scale;
		baseScale = src.baseScale;
		translation = src.translation;
		color = src.color;
		centerRot = src.centerRot;
		scaleCenterRot = src.scaleCenterRot;
		orgCenterRot = src.orgCenterRot;
	}
	return *this;
}

void	Bone::clear() {
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &VAO);
	glDeleteBuffers(1, &EBO);
}

void	Bone::draw(Shader const &shader) {
	shader.use();
	bindVAO();
	bindVBO();
	bindEBO();

	shader.setMat4("model", getModel());
	shader.set3Float("color", color);

	glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}

void	Bone::setCenterRot(Matrix4 centerRot) {
	this->orgCenterRot = centerRot;
	this->scaleCenterRot = centerRot;
	this->centerRot = centerRot;
	updateStack(modelStack);
}

void	Bone::bindVAO() const {
	glBindVertexArray(VAO);
}

void	Bone::bindVBO() const {
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
}

void	Bone::bindEBO() const {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
}

void	Bone::setRotation(Matrix4 rotation) {
	this->rotation = rotation;
	updateStack(modelStack);
}

void	Bone::setScale(Matrix4 scale) {
	this->baseScale = scale;
	this->scale = scale;
	updateStack(modelStack);
}

void	Bone::updateTranslation(Matrix4 translation) {
	this->centerRot = scaleCenterRot * translation;
	updateStack(modelStack);
}

void	Bone::setRotation(float angle, Vector3 axis) {
	rotation = Quaternion(angle, axis).toMatrix();
	updateStack(modelStack);
}

void	Bone::setScale(Vector3 scale) {
	this->baseScale = Matrix4::scaling(scale);
	this->scale = this->baseScale;
	updateStack(modelStack);
}

void	Bone::setTranslation(Vector3 translation) {
	this->translation = Matrix4::translation(translation);
	updateStack(modelStack);
}

void	Bone::changeScale(Vector3 newScale) {
	if (scaleConstraintX != 0.0f && newScale[0] > scaleConstraintX) {
		newScale.setX(scaleConstraintX);
	}
	if (scaleConstraintY != 0.0f && newScale[1] > scaleConstraintY) {
		newScale.setY(scaleConstraintY);
	}
	if (scaleConstraintZ != 0.0f && newScale[2] > scaleConstraintZ) {
		newScale.setZ(scaleConstraintZ);
	}
	this->scale = Matrix4::scaling(Vector3(this->baseScale[0] * newScale[0], this->baseScale[5] * newScale[1], this->baseScale[10] * newScale[2]));
	for (size_t i = 0; i < children.size(); i++) {
		children[i]->updateScale(newScale);
	}
}

void	Bone::updateScale(Vector3 newScale) {
	this->scaleCenterRot = Matrix4::translation(Vector3(orgCenterRot[3] * newScale[0], orgCenterRot[7] * newScale[1], orgCenterRot[11] * newScale[2]));
	this->centerRot = this->scaleCenterRot;
	updateStack(modelStack);
}

Vector3	Bone::getCenterRot() const {
	return Vector3(centerRot[3], centerRot[7], centerRot[11]);
}

Vector3	Bone::getPosition() const {
	return Vector3(translation[3], translation[7], translation[11]);
}

Vector3	Bone::getScale() const {
	return Vector3(scale[0], scale[5], scale[10]);
}

void	Bone::setColor(Vector3 color) {
	this->color = color;
}

void Bone::addChild(Bone *child) {
	children.push_back(child);
}

void	Bone::updateStack(std::vector<Matrix4> parentStack) {
	modelStack = parentStack;
	parentStack.push_back(centerRot);
	parentStack.push_back(rotation);
	parentStack.push_back(translation);
	
	for (size_t i = 0; i < children.size(); i++) {
		children[i]->updateStack(parentStack);
	}
	parentStack.pop_back();
	parentStack.pop_back();
	parentStack.pop_back();
}

Matrix4	Bone::getModel() const {
	Matrix4 stackedModel(1.0f);

	for (size_t i = 0; i < modelStack.size(); i++) {
		stackedModel = stackedModel * modelStack[i];
	}

	stackedModel = stackedModel * centerRot * rotation * translation * scale;

	return stackedModel;
}

void	Bone::applyPose(BoneTransform pose) {
	updateTranslation(Matrix4::translation(pose.getTranslation()));
	setRotation(pose.getRotation().toMatrix());
}

std::string	Bone::getName() const {
	return name;
}

void	Bone::setScaleConstraint(float x, float y, float z) {
	scaleConstraintX = x;
	scaleConstraintY = y;
	scaleConstraintZ = z;
}

void	Bone::setScaleConstraintX(float x) {
	scaleConstraintX = x;
}

void	Bone::setScaleConstraintY(float y) {
	scaleConstraintY = y;
}

void	Bone::setScaleConstraintZ(float z) {
	scaleConstraintZ = z;
}

float	Bone::getScaleConstraintX() const {
	return scaleConstraintX;
}

float	Bone::getScaleConstraintY() const {
	return scaleConstraintY;
}

float	Bone::getScaleConstraintZ() const {
	return scaleConstraintZ;
}