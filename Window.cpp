#include "Window.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

Window::Window(const int width,const int height,const char* title){
    glfwInit();
    window = glfwCreateWindow(width,height,title,0,0);

     if(!window){
        std::cout<<"window"<<std::endl;
    }
    glfwMakeContextCurrent(window);

    gladLoadGL();
}

GLFWwindow* Window::Get(){
    return Window::window;
}