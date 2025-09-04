#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include "colors.h"
#include "keys.h"
#include "stdlib.h"

keyBind setkeyBind(int id, void (*act)(void*), void* args){
  keyBind kb = { .keyId = id, .action = act, .args = args};
    
  return kb;
}

keyBind setkeyBindEmpty(){
  keyBind kb = { .keyId = 0, .action = NULL, .args = NULL};
    
  return kb;
}

keyBind* addKeyBind(keyBind* km, keyBind kb, int id){
  km[id] = kb;
  return km;
}

void processInput(GLFWwindow* mwin, keyBind* km){
  for(int i = 0; i < sizeof(km)/sizeof(keyBind*); i++){ 
    if(glfwGetKey(mwin, km[i].keyId) == GLFW_PRESS){
      km[i].action(km[i].args);
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
}*/

void quit(void*  mwin){
  glfwSetWindowShouldClose(mwin, true);
}


