#include "glad/glad.h"
#include <GLFW/glfw3.h>

int win_size[] = {600, 800};
const char win_name[] = "Acheron";
GLFWwindow* main_win;

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


int main(){
	initGlfw();
	main_win = initWindow(win_size, win_name);
	initGlad();
	
	while(!glfwWindowShouldClose(main_win)){
		glfwSwapBuffers(main_win);
		glfwPollEvents();    
	}

	glfwTerminate();
	return 0;
}
