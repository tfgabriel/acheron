#ifndef __shaders_h_
#define __shaders_h_

#include "glad/glad.h"
#include <GLFW/glfw3.h>

typedef struct{
  GLenum type;
  const char* source;
}shader;

shader* setShader(GLenum type, const char* source);
void initBufferObjects(float* vertices, int stride, unsigned int* VO, shader** shaderVec, unsigned int shaderProgram);
void compileShaders(shader** shaderVec, unsigned int shaderProgram);
void compileShader(shader* _shader, unsigned int shaderProgram);
void draw(int shaderProgram, GLenum type, unsigned int VAO, int verticeCount);
#endif
