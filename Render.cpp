#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "Render.h"
#include <fstream>

std::string ReadShader(std::string filename){
    std::fstream File(filename);
    if(!File.good()){
        std::cout<<"shader file not found"<<std::endl;
        exit(-1);
    };
    
    return std::string(
        std::istreambuf_iterator<char>(File),
        std::istreambuf_iterator<char>());
    
}


void Render::CompileShaders(GLuint program){
    GLuint VertexShader = glCreateShader(GL_VERTEX_SHADER);
    std::string temp = ReadShader("shaders/VertexShader.glsl");
    const char* adapt = temp.c_str();

    glShaderSource(VertexShader,1,&adapt,0);
    glCompileShader(VertexShader);

    GLuint FragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    temp = ReadShader("./shaders/FragmetShader.glsl");
    adapt = temp.c_str();
    glShaderSource(FragmentShader,1,&adapt,0);
    glCompileShader(FragmentShader);

    glAttachShader(program,VertexShader);
    glAttachShader(program,FragmentShader);

    glLinkProgram(program);
    glDeleteShader(VertexShader);
    glDeleteShader(FragmentShader);
}


void Render::Draw(GLFWwindow* window,GLuint Porgram,GLuint &VAO){
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
    glUseProgram(Porgram);
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT,0);
    glfwPollEvents();
    glfwSwapBuffers(window);

}   

void Render::CompileBuffers(GLuint &VBO , GLuint &VAO ,
    GLuint &EBO , const void* verticies , const void* Indices ,
    size_t sizeV , size_t sizeI){

        glGenVertexArrays(1,&VAO);
        glGenBuffers(1,&VBO);
        glGenBuffers(1,&EBO);

        glBindVertexArray(VAO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,EBO);
        glBindBuffer(GL_ARRAY_BUFFER,VBO);

        glBufferData(GL_ARRAY_BUFFER,sizeV,verticies,GL_STATIC_DRAW);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeI,Indices,GL_STATIC_DRAW);

        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,sizeof(float)*6,0);
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,sizeof(float)*6,(char*)(sizeof(float)*3));

        glBindBuffer(GL_ARRAY_BUFFER, 0);
	    glBindVertexArray(0);
}