#ifndef HUMAN_GL_H
#define HUMAN_GL_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <random>

#define WINDOW_WIDTH 1200
#define WINDOW_HEIGHT 800

typedef struct	s_controls {
	std::string	state;
}				t_controls;

class	Camera;

// CALLBACKS
void error_callback(int error, const char *description);
void framebuffer_size_callback(GLFWwindow* window, int width, int height); 
void ft_error(std::string message, GLFWwindow* window);

// INITIALIZATION
GLFWwindow*	initGL(void);
t_controls	initControls(void);

// INPUT
void processInput(GLFWwindow *window, t_controls &controls);
void processMovement(GLFWwindow *window, Camera *camera, t_controls &controls);

int	getFPS();

#endif