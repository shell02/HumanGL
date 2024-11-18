#include "Model.hpp"


Model::Model() {
	torso.addChild(&head);
	torso.addChild(&leftArm);
	leftArm.addChild(&leftForeArm);
	torso.addChild(&rightArm);
	rightArm.addChild(&rightForeArm);
	torso.addChild(&leftThigh);
	leftThigh.addChild(&leftLeg);
	torso.addChild(&rightThigh);
	rightThigh.addChild(&rightLeg);

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

void Model::setupTorso() {
	torso.setColor(Vector3(0.0f, 0.0f, 1.0f));
	torso.setScale(Vector3(1.3f, 2.3f, 0.5f));
}

void Model::setupHead() {
	head.setColor(Vector3(0.0f, 1.0f, 0.0f));
	head.setScale(Vector3(0.6f, 0.6f, 0.6f));
	head.setCenterRot(Matrix4::translation(Vector3(0.0f, 1.25f, 0.0f)));
	head.setTranslation(Vector3(0.0f, .5f, 0.0f));
}

void Model::setupLeftArm() {
	leftArm.setColor(Vector3(1.0f, 0.0f, 0.0f));
	leftArm.setCenterRot(Matrix4::translation(Vector3(-.9f, 1.05f, 0.0f)));
	leftArm.setScale(Vector3(0.4f, 1.3f, 0.5f));
	leftArm.setTranslation(Vector3(0.0f, -0.5f, 0.0f));
}

void Model::setupLeftForeArm() {
	leftForeArm.setColor(Vector3(1.0f, 1.2f, 0.0f));
	leftForeArm.setScale(Vector3(0.4f, 1.2f, 0.5f));
	leftForeArm.setCenterRot(Matrix4::translation(Vector3(0.0f, -1.0f, 0.0f)));
	leftForeArm.setTranslation(Vector3(0.0f, -.5f, 0.0f));
}

void Model::setupRightArm() {
	rightArm.setColor(Vector3(1.0f, 0.0f, 0.0f));
	rightArm.setScale(Vector3(0.4f, 1.3f, 0.5f));
	rightArm.setCenterRot(Matrix4::translation(Vector3(.9f, 1.05f, 0.0f)));
	rightArm.setTranslation(Vector3(0.0f, -0.5f, 0.0f));
}

void Model::setupRightForeArm() {
	rightForeArm.setColor(Vector3(1.0f, 1.2f, 0.0f));
	rightForeArm.setScale(Vector3(0.4f, 1.2f, 0.5f));
	rightForeArm.setCenterRot(Matrix4::translation(Vector3(0.0f, -1.0f, 0.0f)));
	rightForeArm.setTranslation(Vector3(0.0f, -.5f, 0.0f));
}

void Model::setupLeftThigh() {
	leftThigh.setColor(Vector3(1.0f, 0.4f, 0.0f));
	leftThigh.setScale(Vector3(0.5f, 1.5f, 0.5f));
	leftThigh.setCenterRot(Matrix4::translation(Vector3(-.3f, -1.5f, 0.0f)));
	leftThigh.setTranslation(Vector3(0.0f, -.5f, 0.0f));
}

void Model::setupLeftLeg() {
	leftLeg.setColor(Vector3(1.0f, 1.0f, 0.0f));
	leftLeg.setScale(Vector3(0.45f, 1.5f, 0.5f));
	leftLeg.setCenterRot(Matrix4::translation(Vector3(0.0f, -1.1f, 0.0f)));
	leftLeg.setTranslation(Vector3(0.0f, -.5f, 0.0f));
}

void Model::setupRightThigh() {
	rightThigh.setColor(Vector3(1.0f, 0.4f, 0.0f));
	rightThigh.setScale(Vector3(0.5f, 1.5f, 0.5f));
	rightThigh.setCenterRot(Matrix4::translation(Vector3(.3f, -1.5f, 0.0f)));
	rightThigh.setTranslation(Vector3(0.0f, -.5f, 0.0f));
}

void Model::setupRightLeg() {
	rightLeg.setColor(Vector3(1.0f, 1.0f, 0.0f));
	rightLeg.setScale(Vector3(0.45f, 1.5f, 0.5f));
	rightLeg.setCenterRot(Matrix4::translation(Vector3(0.0f, -1.1f, 0.0f)));
	rightLeg.setTranslation(Vector3(0.0f, -.5f, 0.0f));
}

void	Model::applyPoseToBones(std::map<std::string, BoneTransform> pose) {
	torso.applyPose(pose["torso"]);
	head.applyPose(pose["head"]);
	leftArm.applyPose(pose["leftArm"]);
	leftForeArm.applyPose(pose["leftForeArm"]);
	rightArm.applyPose(pose["rightArm"]);
	rightForeArm.applyPose(pose["rightForeArm"]);
	leftThigh.applyPose(pose["leftThigh"]);
	leftLeg.applyPose(pose["leftLeg"]);
	rightThigh.applyPose(pose["rightThigh"]);
	rightLeg.applyPose(pose["rightLeg"]);
}
