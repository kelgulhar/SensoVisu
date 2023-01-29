#include <librealsense2/rs.hpp>
#include <iostream>
#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <Windows.h>



//test code for creation of multiple windows. Those need to be represented in Dear ImGui while handling context -> camera/frame
//this code only generates two windows. the whole programm terminates if any of the two windows is closed
int main() {
	glfwInit();

	GLFWwindow* window1 = glfwCreateWindow(800, 600, "Cam#1", NULL, NULL);
	glfwMakeContextCurrent(window1);

	GLFWwindow* window2 = glfwCreateWindow(640, 480, "Cam#2", NULL, NULL);
	glfwMakeContextCurrent(window2);

	while (!glfwWindowShouldClose(window1) && !glfwWindowShouldClose(window2)) {
		// Render to first window
		glfwMakeContextCurrent(window1);

		// Render to second window
		glfwMakeContextCurrent(window2);

		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}