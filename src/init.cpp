#include "humanGL.h"

void ft_error_non_fatal(std::string message) {
	std::cerr << message << std::endl;
}

void ft_error(std::string message, GLFWwindow* window) {
	std::cerr << message << std::endl;
	glfwDestroyWindow(window);
	glfwTerminate();
	exit(1);
}

void error_callback(int error, const char* description) {
	(void)error;
	std::cerr << "GL_ERROR: " << description << std::endl;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	(void)window;
    glViewport(0, 0, width, height);
}

GLFWwindow*	initGL(void) {
	if (!glfwInit()) {
		std::cerr << "Failed to initialize GLFW" << std::endl;
		exit(1);
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwSetErrorCallback(error_callback);

	GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "HumanGL", NULL, NULL);
	if (!window)
	{
		std::cerr << "Failed to initialize window" << std::endl;
		glfwTerminate();
		exit(1);
	}
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        ft_error("Failed to initialize glad", window);
		glfwDestroyWindow(window);
		glfwTerminate();
		exit(1);
    }

	glEnable(GL_DEPTH_TEST);

	glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback); 
	glfwSwapInterval(1);

	return window;
}

t_controls	initControls(void) {
	t_controls controls;

	controls.state = 0;
	controls.bodyPart = 0;
	controls.reload = false;
	controls.tail = true;
	controls.t = false;
	controls.plus = false;
	controls.minus = false;
	controls.scaleFactor = 1.0f;
	return controls;
}
