#include "Include.h"
struct glVec3{
	GLfloat x,y,z,obj_angle;
	int i;
	glVec3(){
	this->x=0.0f;
	this->y=0.0f;
	this->z=0.0f;
	}
	glVec3(float x,float y,float z){
	this->x=x;
	this->y=y;
	this->z=z;
	}
	void setUser(int i)
	{
		this->i=i;
	}
	int getUser()
	{
		return i;
	}
	}g;
class DrawOpenglPrimitives{
	GLfloat angle;
	
public:
	
	glVec3 top_left,bottom_left,bottom_right,top_right,middle,color;
	void displayTraingle(glVec3 bottom_left,glVec3 bottom_right,glVec3 middle,glVec3 color);
	void displayQuad(glVec3 top_right,glVec3 bottom_right, glVec3 bottom_left,glVec3 top_left,glVec3 color);
	void DrawCircle(float cx, float cy, float r, int num_segments);
	void DrawFilledCircle(float x,float y,double radius,int num_segment);
	
};
void DrawOpenglPrimitives::displayTraingle(glVec3 bottom_left,glVec3 bottom_right,glVec3 middle,glVec3 color){
		glBegin(GL_TRIANGLES);
		glColor3f(color.x,color.y,color.z);
	glVertex3f(bottom_left.x,bottom_left.y,bottom_left.z);
	glVertex3f(middle.x,middle.y,middle.z);
	glVertex3f(bottom_right.x,bottom_right.y,bottom_right.z);
	glEnd();
}
void DrawOpenglPrimitives::displayQuad(glVec3 top_right,glVec3 bottom_right, glVec3 bottom_left,glVec3 top_left,glVec3 color)
{
		glBegin(GL_QUADS);
		glColor3f(color.x,color.y,color.z);
		glVertex3f(top_right.x,top_right.y,top_right.z);
		glVertex3f(bottom_right.x,bottom_right.y,bottom_right.z);
		glVertex3f(bottom_left.x,bottom_left.y,bottom_left.z);
		glVertex3f(top_left.x,top_left.y,top_left.z);	
	glEnd();
}

void DrawOpenglPrimitives::DrawCircle(float cx, float cy, float r, int num_segments)
{
	    glBegin(GL_LINE_LOOP);
    for(int ii = 0; ii < num_segments; ii++)
    {
        float angle = 2.0f * PI * float(ii) / float(num_segments);//get the current angle

        float x = r * cosf(angle);//calculate the x component
        float y = r * sinf(angle);//calculate the y component

        glVertex2f(x + cx, y + cy);//output vertex

    }
    glEnd();
}
void DrawOpenglPrimitives::DrawFilledCircle(float x,float y,double radius,int num_segment)
{
	glColor3f(0.5f,1.0f,0.8f);
    double twicePi = 2.0 * PI;
   
    glBegin(GL_TRIANGLE_FAN); //BEGIN CIRCLE
    glVertex2f(x, y); // center of circle
    for (int i = 0; i <= 100; i++)   {
        glVertex2f (
            (x + (radius * cos(i * twicePi / 20))), (y + (radius * sin(i * twicePi / 20))));
    }
    glEnd(); //EN
}