#pragma once

#include "SimpleEngineCore/Application.hpp"
#include "GLFW/glfw3.h"

namespace SimpleEngine {

	Application::Application()
	{

	}

	Application::~Application()
	{

	}

    int Application::start(unsigned int window_width, unsigned int window_height, const char* title)
    {
        GLFWwindow* window;

        /* Initialize the library */
        if (!glfwInit())
            return -1;

        /* Create a windowed mode window and its OpenGL context */
        window = glfwCreateWindow(window_width, window_height, title, NULL, NULL);
        if (!window)
        {
            glfwTerminate();
            return -1;
        }

        glfwMakeContextCurrent(window);

        while (!glfwWindowShouldClose(window))
        {
            glfwSwapBuffers(window);
            glfwPollEvents();
            onUpdate();
        }

        glfwTerminate();
        return 0;
    }
}