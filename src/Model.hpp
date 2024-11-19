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
		void showTail();

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
		Bone tailBegin;
		Bone tailEnd;

		bool tailVisible;
		
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
		void setupTailBegin();
		void setupTailEnd();
};