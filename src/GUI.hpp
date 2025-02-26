#pragma once

#include "humanGL.h"
#include "Vector.hpp"
#include "Matrix.hpp"
#include "Shader.hpp"

typedef struct	s_button {
	float	x;
	float	y;
	float	width;
	float	height;
	Vector3	color;
}				t_button;

class GUI {
	public:
		GUI();
		GUI(GUI const &src);
		~GUI();

		GUI&	operator=(GUI const &src);

		void	clear();

		void bindVAO() const;
		void bindVBO() const;
		void bindEBO() const;

		void	addButton(float x, float y, float width, float height, Vector3 color);

		void	draw();

		//int		isButtonPressed(float x, float y);

	private:
		unsigned int	VBO;
		unsigned int	VAO;
		unsigned int	EBO;

		std::vector<float>	vertices;
		std::vector<int>	indices;

		Matrix4			projection;

		Shader			shader;

		std::vector<t_button>	buttons;
};

// class Bone {

// 	public:
// 		Bone(std::string name = "Bone");
// 		Bone(Bone const &src);
// 		~Bone();

// 		Bone&	operator=(Bone const &src);

// 		void	clear();

// 		void draw(Shader const &shader);
// 		void bindVAO() const;
// 		void bindVBO() const;
// 		void bindEBO() const;

// 		void	setRotation(Matrix4 rotation);
// 		void	setScale(Matrix4 scale);
// 		void	updateTranslation(Matrix4 translation);

// 		void	setRotation(float angle, Vector3 axis);
// 		void	setScale(Vector3 scale);
// 		void	setTranslation(Vector3 translation);

// 		void	changeScale(Vector3 scale);
// 		void	updateScale(Vector3 scale);

// 		Vector3	getPosition() const;
// 		Vector3	getCenterRot() const;
// 		Vector3	getScale() const;

// 		Matrix4	getModel() const;

// 		void	setColor(Vector3 color);
// 		void	setCenterRot(Matrix4 centerRot);

// 		void	addChild(Bone* child);
// 		void	updateStack(std::vector<Matrix4> modelStack);

// 		void	applyPose(BoneTransform pose);

// 		std::string	getName() const;

// 		void	setScaleConstraint(float x, float y, float z);
// 		void	setScaleConstraintX(float x);
// 		void	setScaleConstraintY(float y);
// 		void	setScaleConstraintZ(float z);

// 		float	getScaleConstraintX() const;
// 		float	getScaleConstraintY() const;
// 		float	getScaleConstraintZ() const;

// 	private:
// 		unsigned int	VBO;
// 		unsigned int	VAO;
// 		unsigned int	EBO;

// 		std::vector<float>	vertices;
// 		std::vector<int>	indices;

// 		Matrix4			rotation;
// 		Matrix4			scale;
// 		Matrix4			baseScale;
// 		Matrix4			translation;

// 		Matrix4			centerRot;
// 		Matrix4			scaleCenterRot;
// 		Matrix4			orgCenterRot;

// 		Vector3			color;

// 		std::vector<Bone*>		children;
// 		std::vector<Matrix4>	modelStack;

// 		std::string		name;

// 		float	scaleConstraintX;
// 		float	scaleConstraintY;
// 		float	scaleConstraintZ;
// };