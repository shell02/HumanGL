#pragma once

#include "humanGL.h"
#include "Vector.hpp"
#include "Matrix.hpp"

class Joint {

	public:
		Joint();
		Joint(Matrix4 translation, Matrix4 rotation, Matrix4 scale);
		~Joint();

		Joint& operator=(Joint const &copy);

		void clear();

		void addChild(Joint* child);

		void updateModel();
		void setHierarchy(std::vector<Matrix4> models);

		void setTranslation(Matrix4 translation);
		void setRotation(Matrix4 rotation);
		void setScale(Matrix4 scale);

		void setTranslation(Vector3 translation);
		void setRotation(float angle, Vector3 rotation);
		void setScale(Vector3 scale);

		Vector3 getTranslation() const;
		Vector3 getScale() const;

		Matrix4 getModel();

	private:
		Matrix4	translation;
		Matrix4 scaledTranslation;
		Matrix4	rotation;
		Matrix4	scale;

		Matrix4	model;
		std::vector<Matrix4>	modelStack;

		std::vector<Joint*>	children;
};