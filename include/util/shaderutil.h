#include <glad/glad.h>
#include <stdio.h>

unsigned int compileShader(const char* shaderSource, GLenum shaderType);
unsigned int createShaderProgram(const char* vertexShaderSource, const char* fragmentShaderSource);