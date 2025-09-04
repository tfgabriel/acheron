#ifndef __keys_h_
#define __keys_h_

#include <GLFW/glfw3.h>

typedef struct{
  int keyId;
  void (*action)();
}keyBind;


keyBind* setkeyBind(int id, void(*act)());
void processInput(GLFWwindow*, keyBind** km, int kms);
/*void quit();
void adjustAlphaPos();
void adjustAlphaNeg();
void adjustRedPos();
void adjustRedNeg();
void changeColor();*/

#endif
