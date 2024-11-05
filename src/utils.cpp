#include "humanGL.h"
#include "Camera.hpp"

void processInput(GLFWwindow *window, t_controls &controls) {
	(void)controls;
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
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