#include "humanGL.h"
#include "../Animation.hpp"
#include "../Keyframe.hpp"
#include "../BoneTransform.hpp"

std::map<std::string, BoneTransform>	getPose1() {
	std::map<std::string, BoneTransform> pose;

	BoneTransform head;
	head.setTranslation(Vector3(0.0f, 0.0f, 0.0f));
	head.setRotation(Quaternion(0.0f, 0.0f, 0.0f, 1.0f));

	BoneTransform torso;
	torso.setTranslation(Vector3(0.0f, 0.0f, 0.0f));
	torso.setRotation(Quaternion(2.0f, Vector3(0.0f, 1.0f, 0.0f)));

	BoneTransform leftArm;
	leftArm.setTranslation(Vector3(0.0f, 0.0f, 0.0f));
	leftArm.setRotation(Quaternion(0.0f, 0.0f, 0.0f, 1.0f));

	BoneTransform leftForeArm;
	leftForeArm.setTranslation(Vector3(0.0f, 0.0f, 0.0f));
	leftForeArm.setRotation(Quaternion(0.0f, 0.0f, 0.0f, 1.0f));

	BoneTransform rightArm;
	rightArm.setTranslation(Vector3(0.0f, 0.0f, 0.0f));
	rightArm.setRotation(Quaternion(0.0f, 0.0f, 0.0f, 1.0f));

	BoneTransform rightForeArm;
	rightForeArm.setTranslation(Vector3(0.0f, 0.0f, 0.0f));
	rightForeArm.setRotation(Quaternion(0.0f, 0.0f, 0.0f, 1.0f));

	BoneTransform leftThigh;
	leftThigh.setTranslation(Vector3(0.0f, 0.0f, 0.0f));
	leftThigh.setRotation(Quaternion(0.0f, 0.0f, 0.0f, 1.0f));

	BoneTransform leftLeg;
	leftLeg.setTranslation(Vector3(0.0f, 0.0f, 0.0f));
	leftLeg.setRotation(Quaternion(0.0f, 0.0f, 0.0f, 1.0f));

	BoneTransform rightThigh;
	rightThigh.setTranslation(Vector3(0.0f, 0.0f, 0.0f));
	rightThigh.setRotation(Quaternion(0.0f, 0.0f, 0.0f, 1.0f));

	BoneTransform rightLeg;
	rightLeg.setTranslation(Vector3(0.0f, 0.0f, 0.0f));
	rightLeg.setRotation(Quaternion(0.0f, 0.0f, 0.0f, 1.0f));

	pose["head"] = head;
	pose["torso"] = torso;
	pose["leftArm"] = leftArm;
	pose["leftForeArm"] = leftForeArm;
	pose["rightArm"] = rightArm;
	pose["rightForeArm"] = rightForeArm;
	pose["leftThigh"] = leftThigh;
	pose["leftLeg"] = leftLeg;
	pose["rightThigh"] = rightThigh;
	pose["rightLeg"] = rightLeg;

	return pose;
}

std::map<std::string, BoneTransform>	getPose2() {
	std::map<std::string, BoneTransform> pose;

	BoneTransform head;
	head.setTranslation(Vector3(0.0f, 0.0f, 0.0f));
	head.setRotation(Quaternion(0.0f, 0.0f, 0.0f, 1.0f));

	BoneTransform torso;
	torso.setTranslation(Vector3(0.0f, 0.0f, 0.0f));
	torso.setRotation(Quaternion(2.0f, Vector3(0.0f, 1.0f, 0.0f)));


	BoneTransform leftArm;
	leftArm.setTranslation(Vector3(0.0f, 0.0f, 0.0f));
	leftArm.setRotation(Quaternion(0.0f, 0.0f, 0.0f, 1.0f));

	BoneTransform leftForeArm;
	leftForeArm.setTranslation(Vector3(0.0f, 0.0f, 0.0f));
	leftForeArm.setRotation(Quaternion(0.0f, 0.0f, 0.0f, 1.0f));

	BoneTransform rightArm;
	rightArm.setTranslation(Vector3(0.0f, 0.0f, 0.0f));
	rightArm.setRotation(Quaternion(0.0f, 0.0f, 0.0f, 1.0f));

	BoneTransform rightForeArm;
	rightForeArm.setTranslation(Vector3(0.0f, 0.0f, 0.0f));
	rightForeArm.setRotation(Quaternion(0.0f, 0.0f, 0.0f, 1.0f));

	BoneTransform leftThigh;
	leftThigh.setTranslation(Vector3(0.0f, 0.0f, 0.0f));
	leftThigh.setRotation(Quaternion(0.0f, 0.0f, 0.0f, 1.0f));

	BoneTransform leftLeg;
	leftLeg.setTranslation(Vector3(0.0f, 0.0f, 0.0f));
	leftLeg.setRotation(Quaternion(0.0f, 0.0f, 0.0f, 1.0f));

	BoneTransform rightThigh;
	rightThigh.setTranslation(Vector3(0.0f, 0.0f, 0.0f));
	rightThigh.setRotation(Quaternion(10.0f, 0.0f, 0.0f, 1.0f));

	BoneTransform rightLeg;
	rightLeg.setTranslation(Vector3(0.0f, 0.0f, 0.0f));
	rightLeg.setRotation(Quaternion(0.0f, 0.0f, 0.0f, 1.0f));

	pose["head"] = head;
	pose["torso"] = torso;
	pose["leftArm"] = leftArm;
	pose["leftForeArm"] = leftForeArm;
	pose["rightArm"] = rightArm;
	pose["rightForeArm"] = rightForeArm;
	pose["leftThigh"] = leftThigh;
	pose["leftLeg"] = leftLeg;
	pose["rightThigh"] = rightThigh;
	pose["rightLeg"] = rightLeg;

	return pose;
}

std::map<std::string, BoneTransform>	getPose3() {
	std::map<std::string, BoneTransform> pose;

	BoneTransform head;
	head.setTranslation(Vector3(0.0f, 0.0f, 0.0f));
	head.setRotation(Quaternion(0.0f, 0.0f, 0.0f, 1.0f));

	BoneTransform torso;
	torso.setTranslation(Vector3(0.0f, 0.0f, 0.0f));
	torso.setRotation(Quaternion(2.0f, Vector3(0.0f, 1.0f, 0.0f)));

	BoneTransform leftArm;
	leftArm.setTranslation(Vector3(0.0f, 0.0f, 0.0f));
	leftArm.setRotation(Quaternion(0.0f, 0.0f, 0.0f, 1.0f));

	BoneTransform leftForeArm;
	leftForeArm.setTranslation(Vector3(0.0f, 0.0f, 0.0f));
	leftForeArm.setRotation(Quaternion(0.0f, 0.0f, 0.0f, 1.0f));

	BoneTransform rightArm;
	rightArm.setTranslation(Vector3(0.0f, 0.0f, 0.0f));
	rightArm.setRotation(Quaternion(0.0f, 0.0f, 0.0f, 1.0f));

	BoneTransform rightForeArm;
	rightForeArm.setTranslation(Vector3(0.0f, 0.0f, 0.0f));
	rightForeArm.setRotation(Quaternion(0.0f, 0.0f, 0.0f, 1.0f));

	BoneTransform leftThigh;
	leftThigh.setTranslation(Vector3(0.0f, 0.0f, 0.0f));
	leftThigh.setRotation(Quaternion(0.0f, 0.0f, 0.0f, 1.0f));

	BoneTransform leftLeg;
	leftLeg.setTranslation(Vector3(0.0f, 0.0f, 0.0f));
	leftLeg.setRotation(Quaternion(0.0f, 0.0f, 0.0f, 1.0f));

	BoneTransform rightThigh;
	rightThigh.setTranslation(Vector3(0.0f, 0.0f, 0.0f));
	rightThigh.setRotation(Quaternion(20.0f, 0.0f, 0.0f, 1.0f));

	BoneTransform rightLeg;
	rightLeg.setTranslation(Vector3(0.0f, 0.0f, 0.0f));
	rightLeg.setRotation(Quaternion(0.0f, 0.0f, 0.0f, 1.0f));

	pose["head"] = head;
	pose["torso"] = torso;
	pose["leftArm"] = leftArm;
	pose["leftForeArm"] = leftForeArm;
	pose["rightArm"] = rightArm;
	pose["rightForeArm"] = rightForeArm;
	pose["leftThigh"] = leftThigh;
	pose["leftLeg"] = leftLeg;
	pose["rightThigh"] = rightThigh;
	pose["rightLeg"] = rightLeg;

	return pose;
}

std::map<std::string, BoneTransform>	getPose4() {
	std::map<std::string, BoneTransform> pose;

	BoneTransform head;
	head.setTranslation(Vector3(0.0f, 0.0f, 0.0f));
	head.setRotation(Quaternion(0.0f, 0.0f, 0.0f, 1.0f));

	BoneTransform torso;
	torso.setTranslation(Vector3(0.0f, 0.0f, 0.0f));
	torso.setRotation(Quaternion(2.0f, Vector3(0.0f, 1.0f, 0.0f)));

	BoneTransform leftArm;
	leftArm.setTranslation(Vector3(0.0f, 0.0f, 0.0f));
	leftArm.setRotation(Quaternion(0.0f, 0.0f, 0.0f, 1.0f));

	BoneTransform leftForeArm;
	leftForeArm.setTranslation(Vector3(0.0f, 0.0f, 0.0f));
	leftForeArm.setRotation(Quaternion(0.0f, 0.0f, 0.0f, 1.0f));

	BoneTransform rightArm;
	rightArm.setTranslation(Vector3(0.0f, 0.0f, 0.0f));
	rightArm.setRotation(Quaternion(0.0f, 0.0f, 0.0f, 1.0f));

	BoneTransform rightForeArm;
	rightForeArm.setTranslation(Vector3(0.0f, 0.0f, 0.0f));
	rightForeArm.setRotation(Quaternion(0.0f, 0.0f, 0.0f, 1.0f));

	BoneTransform leftThigh;
	leftThigh.setTranslation(Vector3(0.0f, 0.0f, 0.0f));
	leftThigh.setRotation(Quaternion(0.0f, 0.0f, 0.0f, 1.0f));

	BoneTransform leftLeg;
	leftLeg.setTranslation(Vector3(0.0f, 0.0f, 0.0f));
	leftLeg.setRotation(Quaternion(0.0f, 0.0f, 0.0f, 1.0f));

	BoneTransform rightThigh;
	rightThigh.setTranslation(Vector3(0.0f, 0.0f, 0.0f));
	rightThigh.setRotation(Quaternion(10.0f, 0.0f, 0.0f, 1.0f));

	BoneTransform rightLeg;
	rightLeg.setTranslation(Vector3(0.0f, 0.0f, 0.0f));
	rightLeg.setRotation(Quaternion(0.0f, 0.0f, 0.0f, 1.0f));

	pose["head"] = head;
	pose["torso"] = torso;
	pose["leftArm"] = leftArm;
	pose["leftForeArm"] = leftForeArm;
	pose["rightArm"] = rightArm;
	pose["rightForeArm"] = rightForeArm;
	pose["leftThigh"] = leftThigh;
	pose["leftLeg"] = leftLeg;
	pose["rightThigh"] = rightThigh;
	pose["rightLeg"] = rightLeg;

	return pose;
}

std::map<std::string, BoneTransform>	getPose5() {
	std::map<std::string, BoneTransform> pose;

	BoneTransform head;
	head.setTranslation(Vector3(0.0f, 0.0f, 0.0f));
	head.setRotation(Quaternion(0.0f, 0.0f, 0.0f, 1.0f));

	BoneTransform torso;
	torso.setTranslation(Vector3(0.0f, 0.0f, 0.0f));
	torso.setRotation(Quaternion(2.0f, Vector3(0.0f, 1.0f, 0.0f)));

	BoneTransform leftArm;
	leftArm.setTranslation(Vector3(0.0f, 0.0f, 0.0f));
	leftArm.setRotation(Quaternion(0.0f, 0.0f, 0.0f, 1.0f));

	BoneTransform leftForeArm;
	leftForeArm.setTranslation(Vector3(0.0f, 0.0f, 0.0f));
	leftForeArm.setRotation(Quaternion(0.0f, 0.0f, 0.0f, 1.0f));

	BoneTransform rightArm;
	rightArm.setTranslation(Vector3(0.0f, 0.0f, 0.0f));
	rightArm.setRotation(Quaternion(0.0f, 0.0f, 0.0f, 1.0f));

	BoneTransform rightForeArm;
	rightForeArm.setTranslation(Vector3(0.0f, 0.0f, 0.0f));
	rightForeArm.setRotation(Quaternion(0.0f, 0.0f, 0.0f, 1.0f));

	BoneTransform leftThigh;
	leftThigh.setTranslation(Vector3(0.0f, 0.0f, 0.0f));
	leftThigh.setRotation(Quaternion(0.0f, 0.0f, 0.0f, 1.0f));

	BoneTransform leftLeg;
	leftLeg.setTranslation(Vector3(0.0f, 0.0f, 0.0f));
	leftLeg.setRotation(Quaternion(0.0f, 0.0f, 0.0f, 1.0f));

	BoneTransform rightThigh;
	rightThigh.setTranslation(Vector3(0.0f, 0.0f, 0.0f));
	rightThigh.setRotation(Quaternion(0.0f, 0.0f, 0.0f, 1.0f));

	BoneTransform rightLeg;
	rightLeg.setTranslation(Vector3(0.0f, 0.0f, 0.0f));
	rightLeg.setRotation(Quaternion(0.0f, 0.0f, 0.0f, 1.0f));

	pose["head"] = head;
	pose["torso"] = torso;
	pose["leftArm"] = leftArm;
	pose["leftForeArm"] = leftForeArm;
	pose["rightArm"] = rightArm;
	pose["rightForeArm"] = rightForeArm;
	pose["leftThigh"] = leftThigh;
	pose["leftLeg"] = leftLeg;
	pose["rightThigh"] = rightThigh;
	pose["rightLeg"] = rightLeg;

	return pose;
}

std::vector<Keyframe>	getWalkingCycle() {
	std::vector<Keyframe> keyframes;

	std::map<std::string, BoneTransform> pose1 = getPose1();
	std::map<std::string, BoneTransform> pose2 = getPose2();
	std::map<std::string, BoneTransform> pose3 = getPose3();
	std::map<std::string, BoneTransform> pose4 = getPose4();
	std::map<std::string, BoneTransform> pose5 = getPose5();

	keyframes.push_back(Keyframe(pose1, 0.0f));
	keyframes.push_back(Keyframe(pose2, 0.5f));
	keyframes.push_back(Keyframe(pose3, 1.0f));
	keyframes.push_back(Keyframe(pose4, 1.5f));
	keyframes.push_back(Keyframe(pose5, 2.0f));


	return keyframes;
}

Animation	walkAnimation() {
	std::vector<Keyframe> keyframes = getWalkingCycle();
	return Animation(keyframes, 2.0f);
}