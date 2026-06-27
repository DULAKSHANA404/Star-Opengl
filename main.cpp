#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Window.h"
#include "Render.h"

int main(){

    GLfloat Verticies[] = {
        0.0f,0.5f,0.0f,
        1.0f,0.84f,0.0f,

        0.5f,-0.5f,0.0f,
        1.0f,0.84f,0.0f,

        -0.5f , -0.5f,0.0f,
        1.0f,0.84f,0.0f,

        -0.5f,0.25f,0.0f,
        1.0f,0.84f,0.0f,

        0.5f,0.25f,0.0f,
        1.0f,0.84f,0.0f,

        0.0f ,-0.75f , 0.0f,
        1.0f,0.84f,0.0f,
    };

    GLuint Indicies[] = {
        0,1,2,
        3,4,5,
    };



    Window windowObj=Window(800,600,"Star");
    GLFWwindow* window = windowObj.Get();

    GLuint program = glCreateProgram();
    Render render;

    GLuint VBO,VAO,EBO;

    render.CompileShaders(program);
    render.CompileBuffers(VBO,VAO,EBO,Verticies,Indicies,sizeof(Verticies),sizeof(Indicies));

    while(!glfwWindowShouldClose(window)){
        render.Draw(window,program,VAO);
    }

    return 0;
}