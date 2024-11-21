#include "humanGL.h"
#include "Camera.hpp"

void processInput(GLFWwindow *window, t_controls &controls) {
	(void)controls;
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);

	if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS) {
		controls.state = WALK;
		controls.reload = true;
	}
	if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS) {
		controls.state = JUMP;
		controls.reload = true;
	}
	if (glfwGetKey(window, GLFW_KEY_3) == GLFW_PRESS) {
		controls.state = IDLE;
		controls.reload = true;
	}
	if (glfwGetKey(window, GLFW_KEY_4) == GLFW_PRESS) {
		controls.state = WAVE;
		controls.reload = true;
	}
	if (glfwGetKey(window, GLFW_KEY_5) == GLFW_PRESS) {
		controls.state = TEST;
		controls.reload = true;
	}

	if (glfwGetKey(window, GLFW_KEY_T) == GLFW_PRESS)
		controls.t = true;
	if (controls.t == true && glfwGetKey(window, GLFW_KEY_T) == GLFW_RELEASE) {
		controls.t = false;
		controls.tail = !controls.tail;
	}

	if (glfwGetKey(window, GLFW_KEY_EQUAL) == GLFW_PRESS && glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) {
		controls.plus = true;
	}
	if (controls.plus == true && (
		glfwGetKey(window, GLFW_KEY_EQUAL) == GLFW_RELEASE ||
		glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_RELEASE)) {
		controls.plus = false;
	}

	if (glfwGetKey(window, GLFW_KEY_MINUS) == GLFW_PRESS) {
		controls.minus = true;
	}
	if (controls.minus == true && glfwGetKey(window, GLFW_KEY_MINUS) == GLFW_RELEASE) {
		controls.minus = false;
	}

	if (glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS) {
		controls.bodyPart = HEAD;
	}
	if (glfwGetKey(window, GLFW_KEY_X) == GLFW_PRESS) {
		controls.bodyPart = TORSO;
	}
	if (glfwGetKey(window, GLFW_KEY_C) == GLFW_PRESS) {
		controls.bodyPart = LEFT_ARM;
	}
	if (glfwGetKey(window, GLFW_KEY_V) == GLFW_PRESS) {
		controls.bodyPart = LEFT_FORE_ARM;
	}
	if (glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS) {
		controls.bodyPart = RIGHT_ARM;
	}
	if (glfwGetKey(window, GLFW_KEY_N) == GLFW_PRESS) {
		controls.bodyPart = RIGHT_FORE_ARM;
	}
	if (glfwGetKey(window, GLFW_KEY_M) == GLFW_PRESS) {
		controls.bodyPart = LEFT_THIGH;
	}
	if (glfwGetKey(window, GLFW_KEY_COMMA) == GLFW_PRESS) {
		controls.bodyPart = LEFT_LEG;
	}
	if (glfwGetKey(window, GLFW_KEY_PERIOD) == GLFW_PRESS) {
		controls.bodyPart = RIGHT_THIGH;
	}
	if (glfwGetKey(window, GLFW_KEY_SLASH) == GLFW_PRESS) {
		controls.bodyPart = RIGHT_LEG;
	}
	
	
	return ;
}

void processMovement(GLFWwindow *window, Camera *camera, t_controls &controls) {
	(void)controls;
	if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
		camera->moveFore();
	if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
		camera->moveBack();
	if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
		camera->moveLeft();
	if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
		camera->moveRight();

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		camera->rotateUp();
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		camera->rotateDown();
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		camera->rotateLeft();
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		camera->rotateRight();
}

int	getFPS() {
	static float	previousTime = 0.0f;
	static int		frameCount = 0;
	static int		fps = 0;
	float			currentTime;

	currentTime = glfwGetTime();
	frameCount++;
	if (currentTime - previousTime >= 1.0f) {
		fps = frameCount;
		frameCount = 0;
		previousTime = currentTime;
	}
	return fps;
}