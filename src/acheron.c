#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include "colors.h"
#include "math.h"
#include "winfuncs.h"
#include "keys.h"

GLFWwindow* mainWin;
RGBAn* curCol;
int keyMapSize = 0;

void quit(){
  glfwSetWindowShouldClose(mainWin, true);
}

int main(){
  mainWin = start();

  keyBind* keyMap[] = {
    setkeyBind(GLFW_KEY_CAPS_LOCK, quit)};

  int keyMapSize = sizeof(keyMap)/sizeof(keyBind*);
  curCol = setRGBAn(0.0f, 0.0f, 0.0f, 0.0f);

	while(!glfwWindowShouldClose(mainWin)){
   processInput(mainWin, keyMap, keyMapSize);
   update(mainWin, curCol);
	} 

  glfwTerminate();
	return 0;
}
