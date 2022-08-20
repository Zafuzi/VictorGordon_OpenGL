#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

int update()
{
	// process polling events like input and window management
	glfwPollEvents();

	return 0;
}

int draw(GLFWwindow* window)
{
	// clear the back buffer and assign the new color to it
	glClear(GL_COLOR_BUFFER_BIT);

	// swap the buffer
	glfwSwapBuffers(window);

	return 0;
}

int main()
{
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(1280, 720, "VictorGordon_OpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	gladLoadGL();

	// specify color of the background
	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);

	// this is from the bottom left to top right for some reason?
	glViewport(0, 0, 1280, 720);

	while (!glfwWindowShouldClose(window))
	{
		update();
		draw(window);
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}
