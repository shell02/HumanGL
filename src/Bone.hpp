#pragma once

#include "humanGL.h"
#include "Vector.hpp"
#include "Matrix.hpp"
#include "Shader.hpp"

class Bone {

	public:
		Bone();
		Bone(Bone const &src);
		~Bone();

		Bone&	operator=(Bone const &src);

		void	clear();

		void draw(Shader const &shader);
		void bindVAO() const;
		void bindVBO() const;
		void bindEBO() const;

		void	setRotation(float angle, Vector3 axis);
		void	setScale(Vector3 scale);
		void	setTranslation(Vector3 translation);

		void	changeScale(Vector3 scale);
		void	updateScale(Vector3 scale);

		Vector3	getPosition() const;
		Vector3	getCenterRot() const;
		Vector3	getScale() const;

		Matrix4	getModel() const;

		void	setColor(Vector3 color);
		void	setCenterRot(Matrix4 centerRot);

		void	addChild(Bone* child);
		void	updateStack(std::vector<Matrix4> modelStack);

	private:
		unsigned int	VBO;
		unsigned int	VAO;
		unsigned int	EBO;

		std::vector<float>	vertices;
		std::vector<int>	indices;

		Matrix4			rotation;
		Matrix4			scale;
		Matrix4			baseScale;
		Matrix4			translation;

		Matrix4			centerRot;
		Matrix4			orgCenterRot;

		Vector3			color;

		std::vector<Bone*>		children;
		std::vector<Matrix4>	modelStack;
};