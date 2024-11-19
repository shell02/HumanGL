#include "humanGL.h"
#include "Camera.hpp"
#include "Shader.hpp"
#include "Text.hpp"
#include "Model.hpp"
#include "Animator.hpp"

int main() {
	GLFWwindow* window = initGL();
	t_controls controls = initControls();

	Shader	shader("shaders/vertex.vs", "shaders/fragment.fs");
	Text	text;

	Camera camera(Vector3(0.0f, -1.5f, 10.0f));

	Model human;

	Animator animator(&human);

	Animation walk;
	walk.loadAnimation("animations/walk.anim");
	if (walk.getError()) {
		ft_error("Could not load animation", window);
		shader.clear();
		text.clear();
		human.clear();

		glfwDestroyWindow(window);
		glfwTerminate();
		return 1;
	}

	animator.startAnimation(walk);

	float lastFrame = 0.0f;
	float deltaTime = 0.0f;

	while (!glfwWindowShouldClose(window)) {
		float currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		processInput(window, controls);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		camera.setDeltaTime(deltaTime);
		camera.setShader(shader);

		processMovement(window, &camera, controls);

		text.renderText("HumanGL", 25.0f, 25.0f, 1.0f, Vector3(0.5f, 0.8f, 0.2f));

		animator.update(deltaTime);
		human.draw(shader);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	shader.clear();
	text.clear();
	human.clear();

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}