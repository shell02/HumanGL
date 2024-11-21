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

	Camera camera(Vector3(9.0f, -1.0f, 7.0f));
	camera.setYaw(-140.0f);

	Model human;

	Animator animator(&human);
	Animation anim;

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

		text.renderText("Choose animation :", 5.0f, (float)WINDOW_HEIGHT - 25.0f, .6f, Vector3(0.0f, 0.0f, 0.0f));
		text.renderText("1 - Walk", 5.0f, (float)WINDOW_HEIGHT - 50.0f, .5f, Vector3(0.0f, 0.0f, 0.0f));
		text.renderText("2 - Jump", 5.0f, (float)WINDOW_HEIGHT - 75.0f, .5f, Vector3(0.0f, 0.0f, 0.0f));
		text.renderText("3 - Idle", 5.0f, (float)WINDOW_HEIGHT - 100.0f, .5f, Vector3(0.0f, 0.0f, 0.0f));
		text.renderText("4 - Wave", 5.0f, (float)WINDOW_HEIGHT - 125.0f, .5f, Vector3(0.0f, 0.0f, 0.0f));
		text.renderText("5 - Live Test", 5.0f, (float)WINDOW_HEIGHT - 150.0f, .5f, Vector3(0.0f, 0.0f, 0.0f));
		text.renderText("T - Toggle tail", 5.0f, (float)WINDOW_HEIGHT - 300.0f, .5f, Vector3(0.0f, 0.0f, 0.0f));
		text.renderText("FPS: " + std::to_string(getFPS()), (float)WINDOW_WIDTH - 100.0f, 5.0f, .2f, Vector3(0.0f, 0.0f, 0.0f));

		if (controls.tail) {
			human.showTail();
		} else {
			human.hideTail();
		}

		if (controls.plus) {
			human.scaleUp(controls.bodyPart);
		}
		if (controls.minus) {
			human.scaleDown(controls.bodyPart);
		}

		if (controls.reload) {
			controls.reload = false;
			
			switch (controls.state)
			{
				case WALK:
					anim.loadAnimation("animations/walk.anim");
					break;
				case JUMP:
					anim.loadAnimation("animations/jump.anim");
					break;
				case IDLE:
					anim.loadAnimation("animations/idle.anim");
					break;
				case WAVE:
					anim.loadAnimation("animations/wave.anim");
					break;
				case TEST:
					anim.loadAnimation("animations/liveTest.anim");
					break;
				default:
					break;	
			}

			if (anim.getError()) {
				animator.stopAnimation();
				anim.clear();
			} else {
				animator.startAnimation(anim);
			}
		}

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