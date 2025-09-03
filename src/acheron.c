#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <stdlib.h>

#define KEY_SPACE 32
#define KEY_ESCAPE 280
#define KEY_UP 

int win_size[] = {600, 800};
const char win_name[] = "Acheron";
GLFWwindow* main_win;

typedef struct{
  int keyId;
  void (*action)(void* arg);
}keyBind;

typedef struct{
  int r, g, b, a;
}colRGBA;

typedef struct{
  float r, g, b, a;
}colRGBAnorm;

float floatMod(float a, float b){
  return a - (int)(a/b) * b;
}

colRGBA* setcolRGBA(int r, int g, int b, int a){
  colRGBA* rgba = malloc(sizeof(colRGBA));
  rgba -> r = r%256;
  rgba -> g = g%256;
  rgba -> b = b%256;
  rgba -> a = a%256;

  return rgba;
}

colRGBAnorm* setcolRGBAnorm(float r, float g, float b, float a){
  colRGBAnorm* rgbaNorm = malloc(sizeof(colRGBAnorm));
  rgbaNorm -> r = floatMod(r, 1.0f);
  rgbaNorm -> g = floatMod(g, 1.0f);
  rgbaNorm -> b = floatMod(b, 1.0f);
  rgbaNorm -> a = floatMod(a, 1.0f);

  return rgbaNorm;
}

colRGBAnorm* normalizeColorRGBA(colRGBA* col){
  colRGBAnorm* rgbaNorm = setcolRGBAnorm(
      (float)(col->r)/256.0f, 
      (float)(col->g)/256.0f, 
      (float)(col->b)/256.0f, 
      (float)(col->a)/256.0f);

  return rgbaNorm;
}

colRGBAnorm* curCol;

keyBind* setkeyBind(int keyId, void (*action)()){
  keyBind* kb = malloc(siz1eof(keyBind));
  kb->keyId = keyId;
  kb->action = action;

  return kb;
}

void changeColor(void* arg){
  curCol->r += 0.001f;
  curCol->g += 0.001f;
  curCol->b += 0.001f;
};

void adjustRed(){
  if(isIncreasing)
    curCol->r += 0.01f;
  else
    curCol->r -= 0.01f;
}
/*void adjustGreen(){
  if(isIncreasing)
    curCol->g += 0.01f;
  else
    curCol->g -= 0.01f;
}
void adjustBlue(){
  if(isIncreasing)
    curCol->b += 0.01f;
  else
    curCol->b -= 0.01f; 
}*/
void adjustAlpha(){
  if(isIncreasing)
    curCol->a += 0.01f;
  else
    curCol->a -= 0.01f;
}

void quit(){
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

void colorPixel(colRGBAnorm* col){
  glClearColor(col->r, col->g, col->b, col->a);
};

void processInput(keyBind ** km, int kms){
  for(int i = 0; i < kms; i++){ 
    if(glfwGetKey(main_win, km[i]->keyId) == GLFW_PRESS){
      km[i]->action();
    }
  }
}

int main(){
	initGlfw();
	main_win = initWindow(win_size, win_name);
	initGlad();

  keyBind* keyMap[] = {
    setkeyBind(GLFW_KEY_SPACE, changeColor),
    setkeyBind(GLFW_KEY_CAPS_LOCK, quit),
    setkeyBind(GLFW_KEY_UP, )};
  int keyMapSize = sizeof(keyMap)/sizeof(keyBind*);

  curCol = setcolRGBAnorm(0.1f, 0.1f, 0.1f, 1.0f);
	while(!glfwWindowShouldClose(main_win)){
    processInput(keyMap, keyMapSize);
		
    colorPixel(curCol);
    glClear(GL_COLOR_BUFFER_BIT);
    
    glfwSwapBuffers(main_win);
		glfwPollEvents();    
	}

  glfwTerminate();
	return 0;
}
