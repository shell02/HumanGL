#pragma once

#include "humanGL.h"
#include "Shader.hpp"
#include "Vector.hpp"
#include "Matrix.hpp"

class Mesh {
	public:
		Mesh(std::vector<float> vertices, std::vector<int> indices = {});
		Mesh(Mesh const &src);
		~Mesh();

		Mesh&	operator=(Mesh const &src);

		void	clear();

		void draw(Shader const &shader);
		void bindVAO() const;
		void bindVBO() const;
		void bindEBO() const;

		void	setRotation(float angle, Vector3 axis);
		void	setScale(Vector3 scale);
		void	setTranslation(Vector3 translation);

		void	addJointModel(Matrix4 jointModel);

		Vector3	getPosition() const;
		Vector3	getScale() const;
		Vector3	getRotation() const;

		void	setColor(Vector3 color);

		void	moveUp(float speed);
		void	moveDown(float speed);
		void	moveLeft(float speed);
		void	moveRight(float speed);
		void	moveForward(float speed);
		void	moveBackward(float speed);

	private:
		unsigned int	VBO;
		unsigned int	VAO;
		unsigned int	EBO;

		std::vector<float>	vertices;
		std::vector<int>	indices;

		Matrix4			model;
		Matrix4			jointModel;
		Matrix4			rotation;
		Matrix4			scale;
		Matrix4			translation;

		bool				hasIndices;

		Vector3			color;

		void	updateModel();
};
