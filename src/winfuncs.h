#ifndef __winfuncs_h_
#define __winfuncs_h_

#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include "colors.h"

void initGlfw();
void initGlad();
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
GLFWwindow* initWindow();
void start(GLFWwindow* mwin);
void colorPixel(RGBAn* col);
void update(GLFWwindow* mwin, RGBAn* col);
#endif
