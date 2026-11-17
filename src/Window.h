#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Window
{
public:
	Window();
	~Window();

public:
	void Run();

private:
	GLFWwindow* window;
};

