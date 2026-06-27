#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

class Render{
public:
    void CompileBuffers(GLuint &VBO , 
        GLuint &VAO , GLuint &EBO , 
        const void* verticies , const void* Indices , 
        size_t sizeV , size_t sizeI);

    void CompileShaders(GLuint program);
    void Draw(GLFWwindow* window,GLuint Porgram,GLuint &VAO);
};