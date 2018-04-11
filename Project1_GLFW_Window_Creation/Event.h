#include "Include.h"
class Eventhandling{
static bool pause;
public:	
	void static key_callback(GLFWwindow* window,int key,int scancode,int action,int mods);
	void mouse_callback(GLFWwindow* window,double xPos,double yPos);
	void mouse_button_callback(GLFWwindow* window,int button,int action,int mode);
	static void setBool(bool pause){pause=pause;}
	static bool getBool(){return pause;}
}EH;
bool Eventhandling::pause=true;
DrawOpenglPrimitives od;
void Eventhandling::key_callback(GLFWwindow* window,int key,int scancode,int action,int mods)
{
	if(key==GLFW_KEY_ESCAPE && action==GLFW_PRESS)
		glfwSetWindowShouldClose(window,GL_TRUE);
	if(key==GLFW_KEY_W && action==GLFW_PRESS)
	{		
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
			glRotatef(g.obj_angle,0.0f,0.0f,1.0f);
			/*if(g.x<1.0f){EH.setBool(true);cout<<EH.pause<<'\n';}			
			else {EH.setBool(false);cout<<EH.pause<<'\n';}
			if(EH.getBool()){g.x+=0.01f;glTranslatef(g.x,0.0,0.0);}else{g.x-=0.01f;glTranslatef(g.x,0.0,0.0);}*/
			if(g.x<=1.0f&&g.x>=-1.0f){g.x+=0.01f;glTranslatef(g.x,0.0,0.0);}else{g.x-=0.01f;glTranslatef(g.x,0.0,0.0);}
	}
	if(key==GLFW_KEY_E && action==GLFW_PRESS)
	{		
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
			glTranslatef(g.x,0.0,0.0);
			glRotatef(g.obj_angle,0.0f,0.0f,1.0f);
			if(g.obj_angle<360.0)
			{
				g.obj_angle+=1.0f;
				glRotatef(g.obj_angle,0.0f,0.0f,1.0f);
			}
	}
	if(key==GLFW_KEY_R && action==GLFW_PRESS)
	{		
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
			//glTranslatef(g.x,0.0,0.0);
			//glRotatef(g.obj_angle,0.0f,0.0f,1.0f);
			if(g.x<1.0&&g.y<1.0)
			{
				
				glScalef(g.x,g.y,1.0f);
				g.x+=0.01f;
				g.y+=0.01f;
				
			}
	}
	  
}