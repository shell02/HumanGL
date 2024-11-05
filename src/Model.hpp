#pragma once

#include "humanGL.h"
#include "Mesh.hpp"
#include "Joint.hpp"

class Model {
	public:
		Model();
		~Model();

		Model& operator=(Model const &copy);

		void draw(Shader shader);
		void update(float deltaTime);

		void clear();

		void test(float angle);

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

	private:
		Mesh torso;
		Mesh head;
		Mesh leftArm;
		Mesh leftForeArm;
		Mesh rightArm;
		Mesh rightForeArm;
		Mesh leftThigh;
		Mesh leftLeg;
		Mesh rightThigh;
		Mesh rightLeg;

		Joint* torsoJoint;
		Joint* headJoint;
		Joint* leftArmJoint;
		Joint* leftForeArmJoint;
		Joint* rightArmJoint;
		Joint* rightForeArmJoint;
		Joint* leftThighJoint;
		Joint* leftLegJoint;
		Joint* rightThighJoint;
		Joint* rightLegJoint;
};