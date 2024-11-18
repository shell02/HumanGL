#pragma once

#include "humanGL.h"
#include "Bone.hpp"
#include "BoneTransform.hpp"

class Model {
	public:
		Model();
		~Model();

		void draw(Shader shader);

		void clear();

		void applyPoseToBones(std::map<std::string, BoneTransform> pose);

	private:
		Bone torso;
		Bone head;
		Bone leftArm;
		Bone leftForeArm;
		Bone rightArm;
		Bone rightForeArm;
		Bone leftThigh;
		Bone leftLeg;
		Bone rightThigh;
		Bone rightLeg;
		
		void setupTorso();
		void setupHead();
		void setupLeftArm();
		void setupLeftForeArm();
		void setupRightArm();
		void setupRightForeArm();
		void setupLeftThigh();
		void setupLeftLeg();
		void setupRightThigh();
		void setupRightLeg();
};