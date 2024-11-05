#include "Model.hpp"

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

void Model::test(float angle)
{
	(void)angle;
	torsoJoint->setScale(Vector3(2.5f, 1.0f, 1.0f));
	// torsoJoint->setScale(Vector3(1.0f > angle ? 1.0f : angle, 2.5f, 1.0f));
	// torsoJoint->setRotation(angle, Vector3(.0f, .0f, 1.0f));
	// leftArmJoint->setRotation(angle, Vector3(0.0f, 0.0f, 1.0f));
	// leftForeArmJoint->setRotation(angle, Vector3(0.0f, 0.0f, 1.0f));
}

Model::Model() :
	torso(cubeVertices, cubeIndices),
	head(cubeVertices, cubeIndices),
	leftArm(cubeVertices, cubeIndices),
	leftForeArm(cubeVertices, cubeIndices),
	rightArm(cubeVertices, cubeIndices),
	rightForeArm(cubeVertices, cubeIndices),
	leftThigh(cubeVertices, cubeIndices),
	leftLeg(cubeVertices, cubeIndices),
	rightThigh(cubeVertices, cubeIndices),
	rightLeg(cubeVertices, cubeIndices) 
{
	torsoJoint = new Joint();
	headJoint = new Joint();
	leftArmJoint = new Joint();
	leftForeArmJoint = new Joint();
	rightArmJoint = new Joint();
	rightForeArmJoint = new Joint();
	leftThighJoint = new Joint();
	leftLegJoint = new Joint();
	rightThighJoint = new Joint();
	rightLegJoint = new Joint();

	torsoJoint->addChild(headJoint);
	torsoJoint->addChild(leftArmJoint);
	torsoJoint->addChild(rightArmJoint);
	torsoJoint->addChild(leftThighJoint);
	torsoJoint->addChild(rightThighJoint);
	leftArmJoint->addChild(leftForeArmJoint);
	leftThighJoint->addChild(leftLegJoint);
	rightArmJoint->addChild(rightForeArmJoint);
	rightThighJoint->addChild(rightLegJoint);
	
	setupTorso();
	setupHead();
	setupLeftArm();
	setupLeftForeArm();
	setupRightArm();
	setupRightForeArm();
	setupLeftThigh();
	setupLeftLeg();
	setupRightThigh();
	setupRightLeg();

}

Model::~Model() {}

void Model::clear() {
	torso.clear();
	head.clear();
	leftArm.clear();
	leftForeArm.clear();
	rightArm.clear();
	rightForeArm.clear();
	leftThigh.clear();
	leftLeg.clear();
	rightThigh.clear();
	rightLeg.clear();
}

void Model::draw(Shader shader) {
	torso.addJointModel(torsoJoint->getModel());
	head.addJointModel(headJoint->getModel());
	leftArm.addJointModel(leftArmJoint->getModel());
	leftForeArm.addJointModel(leftForeArmJoint->getModel());
	rightArm.addJointModel(rightArmJoint->getModel());
	rightForeArm.addJointModel(rightForeArmJoint->getModel());
	leftThigh.addJointModel(leftThighJoint->getModel());
	leftLeg.addJointModel(leftLegJoint->getModel());
	rightThigh.addJointModel(rightThighJoint->getModel());
	rightLeg.addJointModel(rightLegJoint->getModel());


	torso.draw(shader);
	head.draw(shader);
	leftArm.draw(shader);
	leftForeArm.draw(shader);
	rightArm.draw(shader);
	rightForeArm.draw(shader);
	leftThigh.draw(shader);
	leftLeg.draw(shader);
	rightThigh.draw(shader);
	rightLeg.draw(shader);
}

void Model::update(float deltaTime) {
	(void)deltaTime;
}

void Model::setupTorso() {
	torso.setColor(Vector3(0.0f, 0.0f, 1.0f));
	torso.setScale(Vector3(1.0f, 2.5f, .4f));
	torsoJoint->setTranslation(Vector3(0.0f, -0.5f, 0.0f));
}

void Model::setupHead() {
	head.setColor(Vector3(0.0f, 1.0f, 0.0f));
	head.setTranslation(Vector3(0.0f, 0.5f, 0.0f));
	head.setScale(Vector3(0.5f, 0.5f, 0.55f));
	headJoint->setTranslation(Vector3(0.0f, 1.3f, 0.0f));
}

void Model::setupLeftArm() {
	leftArm.setColor(Vector3(1.0f, 0.0f, 0.0f));
	leftArm.setTranslation(Vector3(0.0f, -0.45f, 0.0f));
	leftArm.setScale(Vector3(.3f, 1.25f, .4f));
	leftArmJoint->setTranslation(Vector3(.75f, 1.1f, 0.0f));
}

void Model::setupLeftForeArm() {
	leftForeArm.setColor(Vector3(1.0f, 1.2f, 0.0f));
	leftForeArm.setTranslation(Vector3(0.0f, -0.5f, 0.0f));
	leftForeArm.setScale(Vector3(.3f, 1.35f, .4f)); 
	leftForeArmJoint->setTranslation(Vector3(0.0f, -1.2f, 0.0f));
}

void Model::setupRightArm() {
	rightArm.setColor(Vector3(1.0f, 0.0f, 0.0f));
	rightArm.setTranslation(Vector3(0.0f, -0.45f, 0.0f));
	rightArm.setScale(Vector3(.3f, 1.25f, .4f));
	rightArmJoint->setTranslation(Vector3(-.75f, 1.1f, 0.0f));
}

void Model::setupRightForeArm() {
	rightForeArm.setColor(Vector3(1.0f, 1.2f, 0.0f));
	rightForeArm.setTranslation(Vector3(0.0f, -0.5f, 0.0f));
	rightForeArm.setScale(Vector3(.3f, 1.35f, .4f));
	rightForeArmJoint->setTranslation(Vector3(0.0f, -1.2f, 0.0f));
}

void Model::setupLeftThigh() {
	leftThigh.setColor(Vector3(1.0f, 0.4f, 0.0f));
	leftThigh.setTranslation(Vector3(0.0f, -0.45f, 0.0f));
	leftThigh.setScale(Vector3(.4f, 1.5f, .5f));
	leftThighJoint->setTranslation(Vector3(0.3f, -1.35f, 0.0f));
}

void Model::setupLeftLeg() {
	leftLeg.setColor(Vector3(1.0f, 1.0f, 0.0f));
	leftLeg.setTranslation(Vector3(0.0f, -0.5f, 0.0f));
	leftLeg.setScale(Vector3(0.4f, 1.4f, 0.5f));
	leftLegJoint->setTranslation(Vector3(0.0f, -1.4f, 0.0f));
}

void Model::setupRightThigh() {
	rightThigh.setColor(Vector3(1.0f, 0.4f, 0.0f));
	rightThigh.setTranslation(Vector3(0.0f, -0.45f, 0.0f));
	rightThigh.setScale(Vector3(.4f, 1.5f, .5f));
	rightThighJoint->setTranslation(Vector3(-0.3f, -1.35f, 0.0f));
}

void Model::setupRightLeg() {
	rightLeg.setColor(Vector3(1.0f, 1.0f, 0.0f));
	rightLeg.setTranslation(Vector3(0.0f, -0.5f, 0.0f));
	rightLeg.setScale(Vector3(0.4f, 1.4f, 0.5f));
	rightLegJoint->setTranslation(Vector3(0.0f, -1.4f, 0.0f));
}

Model&	Model::operator=(Model const &src) {
	torso = src.torso;
	head = src.head;
	leftArm = src.leftArm;
	leftForeArm = src.leftForeArm;
	rightArm = src.rightArm;
	rightForeArm = src.rightForeArm;
	leftThigh = src.leftThigh;
	leftLeg = src.leftLeg;
	rightThigh = src.rightThigh;
	rightLeg = src.rightLeg;

	return *this;
}
