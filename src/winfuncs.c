#include "winfuncs.h"
#include "colors.h"

int win_size[] = {600, 800};
const char win_name[] = "Acheron";

void initGlfw(){
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void initGlad(){
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
}

GLFWwindow* initWindow(){

	GLFWwindow* win = glfwCreateWindow(win_size[0], win_size[1], win_name, NULL, NULL);
	glfwMakeContextCurrent(win);
	glfwSetFramebufferSizeCallback(win, framebuffer_size_callback);
	
	return win;
}

void start(GLFWwindow* mwin){
  initGlfw();
  mwin = initWindow();
  initGlad();
}

void framebuffer_size_callback(GLFWwindow* win, int width, int height){
  glViewport(0, 0, width, height);
}

void colorPixel(RGBAn* col){
  glClearColor(col->r, col->g, col->b, col->a);
}

void update(GLFWwindow* mwin, RGBAn* col){	
  colorPixel(col);
  glClear(GL_COLOR_BUFFER_BIT);
    
  glfwSwapBuffers(mwin);
  glfwPollEvents();
}

