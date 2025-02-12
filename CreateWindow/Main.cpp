#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<iostream>


const GLuint SCR_WIDTH = 800;
const GLuint SCR_HEIGHT = 600;

int main()
{
	// Initialize GLFW 
	glfwInit();
	// Configure GLFW -> Version 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Tell OpenGL we will be using only modern functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Create a GLFW window object
	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "How to Create a window", NULL, NULL);
	//Check if the window was properly created
	if(window == NULL)
	{
		std::cout << "Failed to create a GLFW window" << std::endl;
		
		// Free allocated resources, destroys any remaining window or cursors
		glfwTerminate();
		return -1;
	}

	// Making the OpenGL context of the specified window current
	glfwMakeContextCurrent(window);

	// Initialize GLAD in order to properly use the OpenGL functions without failing or crashing
	if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
	
		std::cout << "Failed to initialize GLAD" << std::endl;
		glfwTerminate();
		return -1;
	}

	//Create a loop that only stops when the window is closed
	while (!glfwWindowShouldClose(window)) 
	{
		// Sets the background color
		glClearColor(0.2f,0.8f,1.0f,2.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		//Swaps the front and back buffers of the specified window
		glfwSwapBuffers(window);
		// Processes all pending events
		glfwPollEvents();
	
	}

	// Destroys the specified window object
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}