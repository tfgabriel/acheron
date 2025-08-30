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
  keyBind* kb = malloc(sizeof(keyBind));
  kb -> keyId = keyId;
  kb -> action = action;

  return kb;
}

keyBind keyMap[];
keyBind* keyBindSpace;
keyBind* keyBindEscape;

void changeColor(){
  curCol->r += 0.001f;
  curCol->g += 0.001f;
  curCol->b += 0.001f;
};

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

void processInput(){
  if(glfwGetKey(main_win, keyBindSpace->keyId) == GLFW_PRESS){
    keyBindSpace->action();
  }
  if(glfwGetKey(main_win, keyBindEscape->keyId) == GLFW_PRESS){
    keyBindEscape->action();
  }
}

int main(){
	initGlfw();
	main_win = initWindow(win_size, win_name);
	initGlad();
	
  keyBindSpace = setkeyBind(32, changeColor);
  keyBindEscape = setkeyBind(280, quit);

  curCol = setcolRGBAnorm(0.1f, 0.1f, 0.1f, 1.0f);
	while(!glfwWindowShouldClose(main_win)){
    processInput();
		
    colorPixel(curCol);
    glClear(GL_COLOR_BUFFER_BIT);
    
    glfwSwapBuffers(main_win);
		glfwPollEvents();    
	}

  glfwTerminate();
	return 0;
}
