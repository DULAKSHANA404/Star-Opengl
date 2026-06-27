#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
class Window{

private:
    GLFWwindow* window;
public:
    Window(const int weight,const int height,const char* title);
    ~Window(){
        glfwDestroyWindow(window);
        glfwTerminate();
    }

    GLFWwindow* Get();

};
