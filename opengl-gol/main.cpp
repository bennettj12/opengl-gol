#include <glad/glad.h> 
#include <GLFW/glfw3.h>
#include <iostream>

#include "ogol.h"


int main() {

	glfwInit();
	// Use OpenGL version 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	// Use core profile
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


	// Create a window
	GLFWwindow* window = glfwCreateWindow(800, 600, "Test", NULL, NULL);

	if (window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	// initialize GLAD
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}
	// (lower left x, y, | top right x,y )
	glViewport(0, 0, 800, 600);

	//register window resize callback
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);



	//Main rendering loop
	while (!glfwWindowShouldClose(window)) {

		//swaps color buffer containing color value of each pixel
		glfwSwapBuffers(window);
		//checks if any events are triggered & calls functions we register as callbacks
		glfwPollEvents();

	}

	//clean allocated resources before exiting
	glfwTerminate();
	return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}
