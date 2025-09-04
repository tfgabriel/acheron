#include "winfuncs.h"
#include "colors.h"
#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include "keys.h"

int win_size[] = {600, 800};
const char win_name[] = "Acheron";

void framebuffer_size_callback(GLFWwindow* win, int width, int height){
  glViewport(0, 0, width, height);
}

GLFWwindow* start(){
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	GLFWwindow* mwin = glfwCreateWindow(win_size[0], win_size[1], win_name, NULL, NULL);
	glfwMakeContextCurrent(mwin);
	glfwSetFramebufferSizeCallback(mwin, framebuffer_size_callback);
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

  return mwin;
}

void update(GLFWwindow* mwin, RGBAn* col, keyBind* km){
  processInput(mwin, km);
  glClearColor(col->r, col->g, col->b, col->a);
  glClear(GL_COLOR_BUFFER_BIT);
    
  glfwSwapBuffers(mwin);
  glfwPollEvents();
}

