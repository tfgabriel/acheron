#include "shaders.h"
#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <stdlib.h>

shader* setShader(GLenum type, const char* source){
  shader* sh = malloc(sizeof(shader));
  sh->type = type;
  sh->source = source;

  return sh;
}

void initBufferObjects(float* vertices, int stride, unsigned int* VO, shader** shaderVec, unsigned int shaderProgram){
  glGenBuffers(1, &VO[0]);
  glGenVertexArrays(1, &VO[1]);
  glBindBuffer(GL_ARRAY_BUFFER, VO[0]);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  shaderProgram = glCreateProgram();
  compileShaders(shaderVec, shaderProgram);
  glLinkProgram(shaderProgram);
  
  glVertexAttribPointer(0, stride, GL_FLOAT, GL_FALSE, stride*sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);
}

void compileShaders(shader** shaderVec, unsigned int shaderProgram){
  int shaderVecSize = sizeof(shaderVec)/sizeof(shader);
  for(int i = 0; i < shaderVecSize; i++){
    compileShader(shaderVec[i], shaderProgram);
  }
}

void compileShader(shader* _shader, unsigned int shaderProgram){
  unsigned int shader = glCreateShader(_shader->type);
  glShaderSource(shader, 1, &_shader->source, NULL);
  glCompileShader(shader);
  glAttachShader(shaderProgram, shader);
}

void draw(int shaderProgram, GLenum type, unsigned int VAO, int verticeCount){
  glUseProgram(shaderProgram);
  glBindVertexArray(VAO);
  glDrawArrays(type, 0, verticeCount);
}
