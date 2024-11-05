#include "Mesh.hpp"

Mesh::Mesh(std::vector<float> vertices, std::vector<int> indices) : vertices(vertices), indices(indices), hasIndices(indices.size() > 0) {
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

	if (hasIndices) {
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(int), indices.data(), GL_STATIC_DRAW);
	}

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	model = Matrix4(1.0f);
	jointModel = Matrix4(1.0f);
	rotation = Matrix4(1.0f);
	scale = Matrix4(1.0f);
	translation = Matrix4(1.0f);
	color = Vector3(1.0f, 1.0f, 1.0f);

	updateModel();
}

Mesh::Mesh(Mesh const &src) {
	*this = src;
}

Mesh::~Mesh() {
	vertices.clear();
	indices.clear();
}

Mesh&	Mesh::operator=(Mesh const &src) {
	if (this != &src) {
		clear();
		vertices = src.vertices;
		indices = src.indices;
		hasIndices = src.hasIndices;
		model = src.model;
		jointModel = src.jointModel;
		rotation = src.rotation;
		scale = src.scale;
		translation = src.translation;
		color = src.color;
	}
	return *this;
}

void	Mesh::clear() {
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &VAO);
	glDeleteBuffers(1, &EBO);
}

void	Mesh::draw(Shader const &shader) {
	shader.use();
	bindVAO();
	bindVBO();
	bindEBO();

	shader.setMat4("model", model);
	shader.setMat4("jointModel", jointModel);
	shader.set3Float("color", color);

	if (hasIndices)
		glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
	else
		glDrawArrays(GL_TRIANGLES, 0, vertices.size());
	glBindVertexArray(0);
}

void	Mesh::bindVAO() const {
	glBindVertexArray(VAO);
}

void	Mesh::bindVBO() const {
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
}

void	Mesh::bindEBO() const {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
}

void	Mesh::setRotation(float angle, Vector3 axis) {
	rotation = Matrix4::rotation(angle, axis);
	updateModel();
}

void	Mesh::setScale(Vector3 scale) {
	this->scale = Matrix4::scaling(scale);
	updateModel();
}

void	Mesh::setTranslation(Vector3 translation) {
	this->translation = Matrix4::translation(translation);
	updateModel();
}

void	Mesh::addJointModel(Matrix4 jointModel) {
	this->jointModel = jointModel;
	updateModel();
}

Vector3	Mesh::getPosition() const {
	return Vector3(translation[3], translation[7], translation[11]);
}

Vector3	Mesh::getScale() const {
	return Vector3(scale[0], scale[5], scale[10]);
}

Vector3	Mesh::getRotation() const {
	return Vector3(rotation[0], rotation[4], rotation[8]);
}

void	Mesh::setColor(Vector3 color) {
	this->color = color;
}

void	Mesh::moveUp(float speed) {
	translation = Matrix4::translation(Vector3(0.0f, speed, 0.0f));
	updateModel();
}

void	Mesh::moveDown(float speed) {
	translation = Matrix4::translation(Vector3(0.0f, -speed, 0.0f));
	updateModel();
}

void	Mesh::moveLeft(float speed) {
	translation = Matrix4::translation(Vector3(-speed, 0.0f, 0.0f));
	updateModel();
}

void	Mesh::moveRight(float speed) {
	translation = Matrix4::translation(Vector3(speed, 0.0f, 0.0f));
	updateModel();
}

void	Mesh::moveForward(float speed) {
	translation = Matrix4::translation(Vector3(0.0f, 0.0f, -speed));
	updateModel();
}

void	Mesh::moveBackward(float speed) {
	translation = Matrix4::translation(Vector3(0.0f, 0.0f, speed));
	updateModel();
}

void	Mesh::updateModel() {
	model = scale * rotation * translation;
}

