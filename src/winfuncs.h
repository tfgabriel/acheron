#ifndef __winfuncs_h_
#define __winfuncs_h_

#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include "colors.h"
#include "keys.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
GLFWwindow* start();
void update(GLFWwindow* mwin, RGBAn* col, keyBind* km);
#endif
