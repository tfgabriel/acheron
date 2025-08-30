#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <stdlib.h>

int win_size[] = {600, 800};
const char win_name[] = "Acheron";
GLFWwindow* main_win;

typedef struct{
  int keyId;
  void (*action)();
}keyBind;

keyBind* setkeyBind(int keyId, void (*action)()){
  keyBind* kb = malloc(sizeof(keyBind));
  kb -> keyId = keyId;
  kb -> action = action;

  return kb;
}

keyBind keyMap[];
keyBind* keyBindSpace;

void changeColor(){
};

const void quit(){
  glfwSetWindowShouldClose(main_win, true);
};


void framebuffer_size_callback(GLFWwindow* window, int width, int height){
    glViewport(0, 0, width, height);
}

void initGlfw(){
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void initGlad(){
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
}

GLFWwindow* initWindow(int size[], const char* name){

	GLFWwindow* win = glfwCreateWindow(size[0], size[1], name, NULL, NULL);
	glfwMakeContextCurrent(win);
	glfwSetFramebufferSizeCallback(win, framebuffer_size_callback);
	
	return win;
}


void processInput(){
  if(glfwGetKey(main_win, keyBindSpace->keyId) == GLFW_PRESS){
    keyBindSpace->action();
  }
}

int main(){
	initGlfw();
	main_win = initWindow(win_size, win_name);
	initGlad();
	
  keyBindSpace = setkeyBind(32, quit);

	while(!glfwWindowShouldClose(main_win)){
    processInput();
		glfwSwapBuffers(main_win);
		glfwPollEvents();    
	}

  glfwTerminate();
	return 0;
}
