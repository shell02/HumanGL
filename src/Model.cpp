#include "Model.hpp"


Model::Model() : 
	torso("torso"),
	head("head"),
	leftArm("leftArm"),
	leftForeArm("leftForeArm"),
	rightArm("rightArm"),
	rightForeArm("rightForeArm"),
	leftThigh("leftThigh"),
	leftLeg("leftLeg"),
	rightThigh("rightThigh"),
	rightLeg("rightLeg"),
	tailBegin("tailBegin"),
	tailEnd("tailEnd")
{
	torso.addChild(&head);
	torso.addChild(&leftArm);
	leftArm.addChild(&leftForeArm);
	torso.addChild(&rightArm);
	rightArm.addChild(&rightForeArm);
	torso.addChild(&leftThigh);
	leftThigh.addChild(&leftLeg);
	torso.addChild(&rightThigh);
	rightThigh.addChild(&rightLeg);
	torso.addChild(&tailBegin);
	tailBegin.addChild(&tailEnd);

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
	setupTailBegin();
	setupTailEnd();

	tailVisible = false;

	scaleFactorHead = 1.0f;
	scaleFactorTorso = 1.0f;
	scaleFactorLeftArm = 1.0f;
	scaleFactorLeftForeArm = 1.0f;
	scaleFactorRightArm = 1.0f;
	scaleFactorRightForeArm = 1.0f;
	scaleFactorLeftThigh = 1.0f;
	scaleFactorLeftLeg = 1.0f;
	scaleFactorRightThigh = 1.0f;
	scaleFactorRightLeg = 1.0f;

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
	tailBegin.clear();
	tailEnd.clear();
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
	if (tailVisible) {
		tailBegin.draw(shader);
		tailEnd.draw(shader);
	}
}

void Model::setupTorso() {
	torso.setColor(Vector3(0.0f, 0.0f, 1.0f));
	torso.setScale(Vector3(1.3f, 2.3f, 0.5f));
	torso.setScaleConstraint(3.0f, 3.0f, 3.0f);
}

void Model::setupHead() {
	head.setColor(Vector3(0.0f, 1.0f, 0.0f));
	head.setScale(Vector3(0.6f, 0.6f, 0.6f));
	head.setCenterRot(Matrix4::translation(Vector3(0.0f, 1.25f, 0.0f)));
	head.setTranslation(Vector3(0.0f, .5f, 0.0f));
	head.setScaleConstraint(1.5f, 1.5f, 1.5f);
}

void Model::setupLeftArm() {
	leftArm.setColor(Vector3(1.0f, 0.0f, 0.0f));
	leftArm.setCenterRot(Matrix4::translation(Vector3(-1.0f, 1.05f, 0.0f)));
	leftArm.setScale(Vector3(0.4f, 1.3f, 0.5f));
	leftArm.setTranslation(Vector3(0.0f, -0.5f, 0.0f));
	leftArm.setScaleConstraintX(1.5f);
}

void Model::setupLeftForeArm() {
	leftForeArm.setColor(Vector3(1.0f, 1.2f, 0.0f));
	leftForeArm.setScale(Vector3(0.4f, 1.2f, 0.5f));
	leftForeArm.setCenterRot(Matrix4::translation(Vector3(0.0f, -1.0f, 0.0f)));
	leftForeArm.setTranslation(Vector3(0.0f, -.5f, 0.0f));
	leftForeArm.setScaleConstraintX(1.5f);
}

void Model::setupRightArm() {
	rightArm.setColor(Vector3(1.0f, 0.0f, 0.0f));
	rightArm.setScale(Vector3(0.4f, 1.3f, 0.5f));
	rightArm.setCenterRot(Matrix4::translation(Vector3(1.0f, 1.05f, 0.0f)));
	rightArm.setTranslation(Vector3(0.0f, -0.5f, 0.0f));
	rightArm.setScaleConstraintX(1.5f);
}

void Model::setupRightForeArm() {
	rightForeArm.setColor(Vector3(1.0f, 1.2f, 0.0f));
	rightForeArm.setScale(Vector3(0.4f, 1.2f, 0.5f));
	rightForeArm.setCenterRot(Matrix4::translation(Vector3(0.0f, -1.0f, 0.0f)));
	rightForeArm.setTranslation(Vector3(0.0f, -.5f, 0.0f));
	rightForeArm.setScaleConstraintX(1.5f);
}

void Model::setupLeftThigh() {
	leftThigh.setColor(Vector3(1.0f, 0.4f, 0.0f));
	leftThigh.setScale(Vector3(0.5f, 1.5f, 0.5f));
	leftThigh.setCenterRot(Matrix4::translation(Vector3(-.3f, -1.5f, 0.0f)));
	leftThigh.setTranslation(Vector3(0.0f, -.5f, 0.0f));
	rightForeArm.setScaleConstraintY(1.25f);
}

void Model::setupLeftLeg() {
	leftLeg.setColor(Vector3(1.0f, 1.0f, 0.0f));
	leftLeg.setScale(Vector3(0.45f, 1.5f, 0.5f));
	leftLeg.setCenterRot(Matrix4::translation(Vector3(0.0f, -1.1f, 0.0f)));
	leftLeg.setTranslation(Vector3(0.0f, -.5f, 0.0f));
	rightForeArm.setScaleConstraintY(1.25f);
}

void Model::setupRightThigh() {
	rightThigh.setColor(Vector3(1.0f, 0.4f, 0.0f));
	rightThigh.setScale(Vector3(0.5f, 1.5f, 0.5f));
	rightThigh.setCenterRot(Matrix4::translation(Vector3(.3f, -1.5f, 0.0f)));
	rightThigh.setTranslation(Vector3(0.0f, -.5f, 0.0f));
	rightForeArm.setScaleConstraintY(1.25f);
}

void Model::setupRightLeg() {
	rightLeg.setColor(Vector3(1.0f, 1.0f, 0.0f));
	rightLeg.setScale(Vector3(0.45f, 1.5f, 0.5f));
	rightLeg.setCenterRot(Matrix4::translation(Vector3(0.0f, -1.1f, 0.0f)));
	rightLeg.setTranslation(Vector3(0.0f, -.5f, 0.0f));
	rightForeArm.setScaleConstraintY(1.25f);
}

void Model::setupTailBegin() {
	tailBegin.setColor(Vector3(1.0f, 0.0f, 1.0f));
	tailBegin.setScale(Vector3(0.3f, 0.3f, 1.25f));
	tailBegin.setCenterRot(Matrix4::translation(Vector3(0.0f, -0.9f, -0.5f)));
	tailBegin.setTranslation(Vector3(0.0f, 0.0f, -0.5f));
	tailBegin.setRotation(Quaternion(35.0f, Vector3(1.0f, 0.0f, 0.0f)).toMatrix());
	tailBegin.setScaleConstraintZ(1.5f);
}

void Model::setupTailEnd() {
	tailEnd.setColor(Vector3(1.0f, 0.0f, 1.0f));
	tailEnd.setScale(Vector3(0.3f, 0.3f, 1.0f));
	tailEnd.setCenterRot(Matrix4::translation(Vector3(0.0f, 0.0f, -.65f)));
	tailEnd.setTranslation(Vector3(0.0f, 0.0f, -0.5f));
	tailEnd.setRotation(Quaternion(35.0f, Vector3(1.0f, 0.0f, 0.0f)).toMatrix());
	tailEnd.setScaleConstraintZ(1.5f);
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

	if (pose.find("tailBegin") == pose.end() || pose.find("tailEnd") == pose.end())
		return ;
	tailBegin.applyPose(pose["tailBegin"]);
	tailEnd.applyPose(pose["tailEnd"]);
}

void	Model::scaleUp(int bodyPart) {
	switch (bodyPart)
	{
		case HEAD:
			scaleFactorHead += 0.005f;
			head.changeScale(Vector3(scaleFactorHead, scaleFactorHead, scaleFactorHead));
			break;

		case TORSO:
			scaleFactorTorso += 0.005f;
			torso.changeScale(Vector3(scaleFactorTorso, scaleFactorTorso, scaleFactorTorso));
			tailBegin.changeScale(Vector3(scaleFactorTorso, scaleFactorTorso, scaleFactorTorso));
			tailEnd.changeScale(Vector3(scaleFactorTorso, scaleFactorTorso, scaleFactorTorso));
			break;

		case LEFT_ARM:
			if (scaleFactorLeftArm > leftArm.getScaleConstraintX())
				return ;
			scaleFactorLeftArm += 0.005f;
			leftArm.changeScale(Vector3(scaleFactorLeftArm, scaleFactorLeftArm, scaleFactorLeftArm));
			break;
		
		case LEFT_FORE_ARM:
			if (scaleFactorLeftForeArm > leftForeArm.getScaleConstraintX())
				return ;
			scaleFactorLeftForeArm += 0.005f;
			leftForeArm.changeScale(Vector3(scaleFactorLeftForeArm, scaleFactorLeftForeArm, scaleFactorLeftForeArm));
			break;

		case RIGHT_ARM:
			if (scaleFactorRightArm > rightArm.getScaleConstraintX())
				return ;
			scaleFactorRightArm += 0.005f;
			rightArm.changeScale(Vector3(scaleFactorRightArm, scaleFactorRightArm, scaleFactorRightArm));
			break;

		case RIGHT_FORE_ARM:
			if (scaleFactorRightForeArm > rightForeArm.getScaleConstraintX())
				return ;
			scaleFactorRightForeArm += 0.005f;
			rightForeArm.changeScale(Vector3(scaleFactorRightForeArm, scaleFactorRightForeArm, scaleFactorRightForeArm));
			break;

		case LEFT_THIGH:
			if (scaleFactorLeftThigh > leftThigh.getScaleConstraintY())
				return ;
			scaleFactorLeftThigh += 0.005f;
			leftThigh.changeScale(Vector3(scaleFactorLeftThigh, scaleFactorLeftThigh, scaleFactorLeftThigh));
			break;

		case LEFT_LEG:
			if (scaleFactorLeftLeg > leftLeg.getScaleConstraintY())
				return ;
			scaleFactorLeftLeg += 0.005f;
			leftLeg.changeScale(Vector3(scaleFactorLeftLeg, scaleFactorLeftLeg, scaleFactorLeftLeg));
			break;

		case RIGHT_THIGH:
			if (scaleFactorRightThigh > rightThigh.getScaleConstraintY())
				return ;
			scaleFactorRightThigh += 0.005f;
			rightThigh.changeScale(Vector3(scaleFactorRightThigh, scaleFactorRightThigh, scaleFactorRightThigh));
			break;

		case RIGHT_LEG:
			if (scaleFactorRightLeg > rightLeg.getScaleConstraintY())
				return ;
			scaleFactorRightLeg += 0.005f;
			rightLeg.changeScale(Vector3(scaleFactorRightLeg, scaleFactorRightLeg, scaleFactorRightLeg));
			break;
		
		default:
			break;
	}

	return ;
}

void	Model::scaleDown(int bodyPart) {
	switch (bodyPart)
	{
		case HEAD:
			if (scaleFactorHead < 0.5f)
				return ;
			scaleFactorHead -= 0.005f;
			head.changeScale(Vector3(scaleFactorHead, scaleFactorHead, scaleFactorHead));
			break;

		case TORSO:
			if (scaleFactorTorso < 0.6f)
				return ;
			scaleFactorTorso -= 0.005f;
			torso.changeScale(Vector3(scaleFactorTorso, scaleFactorTorso, scaleFactorTorso));
			tailBegin.changeScale(Vector3(scaleFactorTorso, scaleFactorTorso, scaleFactorTorso));
			tailEnd.changeScale(Vector3(scaleFactorTorso, scaleFactorTorso, scaleFactorTorso));
			break;

		case LEFT_ARM:
			if (scaleFactorLeftArm < 0.5f)
				return ;
			scaleFactorLeftArm -= 0.005f;
			leftArm.changeScale(Vector3(scaleFactorLeftArm, scaleFactorLeftArm, scaleFactorLeftArm));
			break;
		
		case LEFT_FORE_ARM:
			if (scaleFactorLeftForeArm < 0.5f)
				return ;
			scaleFactorLeftForeArm -= 0.005f;
			leftForeArm.changeScale(Vector3(scaleFactorLeftForeArm, scaleFactorLeftForeArm, scaleFactorLeftForeArm));
			break;

		case RIGHT_ARM:
			if (scaleFactorRightArm < 0.5f)
				return ;
			scaleFactorRightArm -= 0.005f;
			rightArm.changeScale(Vector3(scaleFactorRightArm, scaleFactorRightArm, scaleFactorRightArm));
			break;

		case RIGHT_FORE_ARM:
			if (scaleFactorRightForeArm < 0.5f)
				return ;
			scaleFactorRightForeArm -= 0.005f;
			rightForeArm.changeScale(Vector3(scaleFactorRightForeArm, scaleFactorRightForeArm, scaleFactorRightForeArm));
			break;

		case LEFT_THIGH:
			if (scaleFactorLeftThigh < 0.5f)
				return ;
			scaleFactorLeftThigh -= 0.005f;
			leftThigh.changeScale(Vector3(scaleFactorLeftThigh, scaleFactorLeftThigh, scaleFactorLeftThigh));
			break;

		case LEFT_LEG:
			if (scaleFactorLeftLeg < 0.5f)
				return ;
			scaleFactorLeftLeg -= 0.005f;
			leftLeg.changeScale(Vector3(scaleFactorLeftLeg, scaleFactorLeftLeg, scaleFactorLeftLeg));
			break;

		case RIGHT_THIGH:
			if (scaleFactorRightThigh < 0.5f)
				return ;
			scaleFactorRightThigh -= 0.005f;
			rightThigh.changeScale(Vector3(scaleFactorRightThigh, scaleFactorRightThigh, scaleFactorRightThigh));
			break;

		case RIGHT_LEG:
			if (scaleFactorRightLeg < 0.5f)
				return ;
			scaleFactorRightLeg -= 0.005f;
			rightLeg.changeScale(Vector3(scaleFactorRightLeg, scaleFactorRightLeg, scaleFactorRightLeg));
			break;

		default:
			break;

	}
	return ;
}

void	Model::showTail() {
	tailVisible = true;
}

void	Model::hideTail() {
	tailVisible = false;
}
