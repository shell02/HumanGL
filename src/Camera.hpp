#pragma once

#include "humanGL.h"
#include "Shader.hpp"
#include "Vector.hpp"
#include "Matrix.hpp"

class Camera {
	public:
		Camera(Vector3 cameraPos = Vector3(0.0f, 0.0f, 3.0f), Vector3 cameraFront = Vector3(0.0f, 0.0f, -1.0f), Vector3 upVector = Vector3(0.0f, 1.0f, 0.0f));
		Camera(const Camera& copy);
		~Camera();

		Camera& operator=(const Camera& copy);

		Matrix4	LookAt(void) const;
		Matrix4	Projection(void) const;

		void	updateFront(void);

		void	setYaw(float yaw);
		void	setPitch(float pitch);

		void	updatePos(Vector3 newPos);
		void	updateFront(Vector3 newFront);
		void	updateUp(Vector3 newUp);

		void	moveLeft();
		void	moveRight();
		void	moveFore();
		void	moveBack();

		void	rotateLeft();
		void	rotateRight();
		void	rotateUp();
		void	rotateDown();

		void	setDeltaTime(float d);

		Vector3	getPos() const;

		void	setShader(Shader const &shader) const;

	private:
		Vector3	cameraPos;
		Vector3	cameraFront;
		Vector3	upVector;

		float	deltatime;
		float	pitch;
		float	yaw;

		float	moveSpeed;
		float	rotateSpeed;
};