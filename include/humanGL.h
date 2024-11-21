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

#define WALK 1
#define JUMP 2
#define IDLE 3
#define BOXE 4
#define WAVE 5
#define TEST 6

#define HEAD 1
#define TORSO 2
#define LEFT_ARM 3
#define LEFT_FORE_ARM 4
#define RIGHT_ARM 5
#define RIGHT_FORE_ARM 6
#define LEFT_THIGH 7
#define LEFT_LEG 8
#define RIGHT_THIGH 9
#define RIGHT_LEG 10

typedef struct	s_controls {
	int			state;
	int			bodyPart;
	bool		t;
	bool		reload;
	bool		tail;
	bool		plus;
	bool		minus;
	float		scaleFactor;
}				t_controls;

class	Camera;
class	Animation;

// CALLBACKS
void error_callback(int error, const char *description);
void framebuffer_size_callback(GLFWwindow* window, int width, int height); 
void ft_error(std::string message, GLFWwindow* window);
void ft_error_non_fatal(std::string message);

// INITIALIZATION
GLFWwindow*	initGL(void);
t_controls	initControls(void);

// INPUT
void processInput(GLFWwindow *window, t_controls &controls);
void processMovement(GLFWwindow *window, Camera *camera, t_controls &controls);

int	getFPS();

// ANIMATIONS
Animation	walkAnimation();

#endif