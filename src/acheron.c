#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include "colors.h"
#include "math.h"
#include "winfuncs.h"
#include "keys.h"
#include "shaders.h"

GLFWwindow* mainWin;
RGBAn* curCol;
int keyMapSize = 0;
float vertices[] = {
  -0.5f, -0.5f, 0.0f,
  0.5f, -0.5f, 0.0f,
  0.0f, 0.5f, 0.0f
};
int verticeStride = 3;
unsigned int vertexObject[2] = {0, 0};
unsigned int shaderProgram = 0;
 
const char* vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";


const char* fragmentShaderSource = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\0";

void quit(){
  glfwSetWindowShouldClose(mainWin, true);
}

int main(){
  mainWin = start();

  keyBind* keyMap[] = {
    setkeyBind(GLFW_KEY_CAPS_LOCK, quit)};

  shader* shaderVec[] = { 
    setShader(GL_VERTEX_SHADER, vertexShaderSource), 
    setShader(GL_FRAGMENT_SHADER, fragmentShaderSource)};

  initBufferObjects(vertices, verticeStride, vertexObject, shaderVec, shaderProgram);
  int keyMapSize = sizeof(keyMap)/sizeof(keyBind*);
  curCol = setRGBAn(0.0f, 0.0f, 0.0f, 0.0f);

	while(!glfwWindowShouldClose(mainWin)){
   processInput(mainWin, keyMap, keyMapSize);
   update(mainWin, curCol);
   draw(shaderProgram, GL_TRIANGLES, vertexObject[1], sizeof(vertices)/(sizeof(float)*verticeStride));
	} 

  glfwTerminate();
	return 0;
}
