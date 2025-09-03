#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>

int win_size[] = {600, 800};
const char win_name[] = "Acheron";
GLFWwindow* main_win;
int useLogs = 1;

typedef struct{
  int keyId;
  void (*action)();
}keyBind;

typedef struct{
  float r, g, b, a;
}RGBAn;

float absf(float a){
  if(a<0.0f)
    a= -a;
  return a;
}
float floatMod(float a, float b){
  return absf(a - (int)(a/b) * b);
}

float clampf(float a, float min, float max){
  if(a<=min)
    a = min;
  else if(a>=max)
    a = max;
  return a;
}

float clampfnorm(float a) {
  return clampf(a, 0.0f, 1.0f);
}

RGBAn* setRGBAn(float r, float g, float b, float a){
  RGBAn* rgban = malloc(sizeof(RGBAn));
  rgban -> r = clampfnorm(r);
  rgban -> g = clampfnorm(g);
  rgban -> b = clampfnorm(b);
  rgban -> a = clampfnorm(a);

  return rgban;
}

keyBind* setkeyBind(int keyId, void (*action)()){
  keyBind* kb = malloc(sizeof(keyBind));
  kb->keyId = keyId;
  kb->action = action;

  return kb;
}

RGBAn* addRGBAn(RGBAn* col1, RGBAn* col2){
  RGBAn* col = setRGBAn(
      col1->r + col2->r, 
      col1->g + col2->g, 
      col1->b + col2->b, 
      col1->a + col2->a);

  return col;
}

RGBAn* addRGBAnScalar(RGBAn* col1, float s){
  RGBAn* col = setRGBAn(
      col1->r + s, 
      col1->g + s, 
      col1->b + s, 
      col1->a);

  return col;
}

RGBAn* subtractRGBAn(RGBAn* col1, RGBAn* col2){
  RGBAn* col = setRGBAn(
      col1->r - col2->r, 
      col1->g - col2->g, 
      col1->b - col2->b, 
      col1->a - col2->a);

  return col;
}

RGBAn* curCol;

void changeColor(){
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
}

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

void colorPixel(RGBAn* col){
  glClearColor(col->r, col->g, col->b, col->a);
};

void processInput(keyBind ** km, int kms){
  for(int i = 0; i < kms; i++){ 
    if(glfwGetKey(main_win, km[i]->keyId) == GLFW_PRESS){
      km[i]->action();
    }
  }
}

void logColor(int ul){
  if(ul){
   printf("red %.2f green %.2f blue %.2f alpha %.2f \n", curCol->r, curCol->g, curCol->b, curCol->a);
  }
}
int main(){
	initGlfw();
	main_win = initWindow(win_size, win_name);
	initGlad();

  keyBind* keyMap[] = {
    setkeyBind(GLFW_KEY_SPACE, changeColor),
    setkeyBind(GLFW_KEY_CAPS_LOCK, quit),
    setkeyBind(GLFW_KEY_UP, adjustAlphaPos),
    setkeyBind(GLFW_KEY_DOWN, adjustAlphaNeg),
    setkeyBind(GLFW_KEY_LEFT, adjustRedNeg),
    setkeyBind(GLFW_KEY_RIGHT, adjustRedPos) };
  int keyMapSize = sizeof(keyMap)/sizeof(keyBind*);

  curCol = setRGBAn(0.0f, 0.0f, 0.0f, 0.0f);
	while(!glfwWindowShouldClose(main_win)){
    processInput(keyMap, keyMapSize);
		
    colorPixel(curCol);
    glClear(GL_COLOR_BUFFER_BIT);
    
    glfwSwapBuffers(main_win);
		glfwPollEvents();

    logColor(useLogs);
	}

  glfwTerminate();
	return 0;
}
