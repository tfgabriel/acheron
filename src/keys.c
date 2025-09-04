#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include "colors.h"
#include "keys.h"
#include "stdlib.h"

keyBind* setkeyBind(int id, void (*act)()){
  keyBind* kb = malloc(sizeof(keyBind));
  kb->keyId = id;
  kb->action = act;

  return kb;
}


void processInput(GLFWwindow* mwin, keyBind ** km, int kms){
  for(int i = 0; i < kms; i++){ 
    if(glfwGetKey(mwin, km[i]->keyId) == GLFW_PRESS){
      km[i]->action();
    }
  }
}

/*void changeColor(){
  curCol = addRGBAnScalar(curCol, 0.001f);
}

void adjustRedPos(){
  curCol = addRGBAn(curCol, setRGBAn(0.01f, 0.0f, 0.0f, 0.0f));
}
void adjustRedNeg(){
  curCol = subtractRGBAn(curCol, setRGBAn(0.01f, 0.0f, 0.0f, 0.0f));
}

void adjustAlphaPos(){
  curCol = addRGBAn(curCol, setRGBAn(0.0f, 0.0f, 0.0f, 0.01f));
}
void adjustAlphaNeg(){
  curCol = subtractRGBAn(curCol, setRGBAn(0.0f, 0.0f, 0.0f, 0.01f));
}

void quit(){
  glfwSetWindowShouldClose(main_win, true);
}*/


