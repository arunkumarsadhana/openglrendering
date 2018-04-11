

#include "Display.h"
#include "Event.h"
const GLint WIDTH=800,HEIGHT=600;
int main()
{
	glfwInit();//Intialiing the framework
	GLFWwindow* window=glfwCreateWindow(WIDTH,HEIGHT,"First example",NULL,NULL);//setting the height and width of the window
	glfwMakeContextCurrent(window);
	glewInit();
	//glfwSetInputMode(window,GLFW_STICKY_KEYS,GL_TRUE);//outside the game loop
	DrawOpenglPrimitives dop; 
	//Eventhandling e;
	glfwSetKeyCallback(window,Eventhandling::key_callback);
	while(!glfwWindowShouldClose(window))//game loop		
	{
		glfwPollEvents();
		glClearColor(0.5f,0.2f,0.5f,1.0f);// R(red) G(Green) B(Blue) A(alpha)
		glClear(GL_COLOR_BUFFER_BIT);
		dop.displayTraingle(glVec3(0.2f,0.2f,0.0f),glVec3(0.4f,0.4f,0.0f),glVec3(0.6f,0.2f,0.0f),glVec3(1.0f,0.5f,0.5f));
		dop.displayQuad(glVec3(-0.6f,0.4f,0.0f),glVec3(-0.6f,0.2f,0.0f),glVec3(-0.2f,0.2f,0.0f),glVec3(-0.2f,0.4f,0.0f),glVec3(1.0f,0.0f,0.0f));
		//dop.displayQuad();
		dop.DrawCircle(-0.3f,-0.3f,0.1f,100);
		dop.DrawFilledCircle(0.4f,-0.3f,0.1f,20);
		glfwSwapBuffers(window);
	}
	glfwTerminate();
	return 0;
}
