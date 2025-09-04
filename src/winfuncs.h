#ifndef __winfuncs_h_
#define __winfuncs_h_

#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include "colors.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
GLFWwindow* initWindow();
GLFWwindow* start();
void update(GLFWwindow* mwin, RGBAn* col);
#endif
