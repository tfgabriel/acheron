#ifndef __keys_h_
#define __keys_h_

#include <GLFW/glfw3.h>

typedef struct{
  int keyId;
  void (*action)(void*);
  void* args;
}keyBind;


keyBind setkeyBind(int id, void(*act)(void*), void* args);
keyBind setkeyBindEmpty();
keyBind* addKeyBind(keyBind* km, keyBind kb, int id);
void processInput(GLFWwindow*, keyBind* km);
void quit(void* mwin);
void adjustAlphaPos();
void adjustAlphaNeg();
void adjustRedPos();
void adjustRedNeg();
void changeColor();

#endif
