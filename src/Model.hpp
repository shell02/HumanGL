#pragma once

#include "humanGL.h"
#include "Bone.hpp"

class Model {
	public:
		Model();
		~Model();

		Model& operator=(Model const &copy);

		void draw(Shader shader);
		void update(float deltaTime);

		void clear();


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

		float time = 0.01f;
		float speed = 0.1f;
		
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