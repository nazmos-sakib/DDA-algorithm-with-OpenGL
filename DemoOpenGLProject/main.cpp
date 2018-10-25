//sir
#include <iostream>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h> 
#include <conio.h>
#include <math.h> 

using namespace std;

void  reshapeLine(int w, int h);
void  reshapePoint(int w, int h);
void DrawPointFunctionSet();
void DrawLineFunctionSet();

class ObjectMovment 
{
public:

	int x_axis;
	int y_axis;
	float x;
	float y;
	float points[10][2];
	int rowSize;
	int columSize;
	float translation_dx_value;
	float translation_dy_value;
	int rotationAngle;

	ObjectMovment (){}
	~ObjectMovment ();

	//ObjectMovment(int , int, float, float,float * ,int,int,float,float);
	void setNecessaryPointValue(int , int, float, float,float * ,int,int,float,float);
	void setNecessaryLineValue(int , int, float, float,float * ,int,int,int);

	void drawAxis();
	void printPoint(int,int);

	void DrawPointFunction();
	void pointPlot();
	

	void DrawLineFunction();
	void linePlot();
	

private:

};

ObjectMovment ::~ObjectMovment ()
{
}

void ObjectMovment :: printPoint(int rowSize,int columSize)
{
	for (int i = 0; i < rowSize; i++)
	{
		for (int j = 0; j < columSize; j++)
		{
			//this->points[i][j] = *((points+i*columSize) + j);
			  cout<< this->points[i][j]<<"  "; //*((points+i*columSize) + j)<<"--";
		}
	}
}


//ObjectMovment ::ObjectMovment (int x_axis, int y_axis, float x, float y,float * points, int rowSize,int columSize,float translation_dx_value = 0.0,float translation_dy_value = 0.0)
void	ObjectMovment :: setNecessaryPointValue (int x_axis, int y_axis, float x, float y,float * points, int rowSize,int columSize,float translation_dx_value = 0.0,float translation_dy_value = 0.0)
{
	this->x_axis = x_axis;
	this->y_axis = y_axis;
	this->x = x;
	this->y = y;

	this->rowSize = rowSize;
	this->columSize = columSize;

	this->translation_dx_value = translation_dx_value;
	this->translation_dy_value = translation_dy_value;

	for (int i = 0; i < rowSize; i++)
	{
		for (int j = 0; j < columSize; j++)
		{
			this->points[i][j] = *((points+i*columSize) + j);
		}
	}

	
}



void	ObjectMovment :: setNecessaryLineValue (int x_axis, int y_axis, float x, float y,float * points, int rowSize,int columSize,int rotationAngle = 0)
{
	this->x_axis = x_axis;
	this->y_axis = y_axis;
	this->x = x;
	this->y = y;

	this->rowSize = rowSize;
	this->columSize = columSize;
	 
	this->rotationAngle = rotationAngle;

	for (int i = 0; i < rowSize; i++)
	{
		for (int j = 0; j < columSize; j++)
		{
			this->points[i][j] = *((points+i*columSize) + j);
		}
	}

	
}




void ObjectMovment :: drawAxis()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	glColor3d(0.0, 0.0, 0.0);
	glLineWidth(1.0);

	
	

	for (int i = - this->y_axis; i < y_axis; i++)
	{
		glBegin(GL_LINES);
	glVertex2i(i, this->y_axis);
	glVertex2i(i, -this->y_axis);
	glEnd();

	}
	
	

	for (int i = - this->x_axis ; i < y_axis; i++)
	{
		glBegin(GL_LINES);
	glVertex2i(-this->x_axis, i);
	glVertex2i(this->x_axis, i);
	glEnd();
	}

	glColor3d(1.0, 0.0, 0.0);

	glBegin(GL_LINES);
	glVertex2i(-this->x_axis, 0);
	glVertex2i(this->x_axis, 0);
	glEnd();

	glBegin(GL_LINES);
	glVertex2i(0, this->y_axis);
	glVertex2i(0, -this->y_axis);
	glEnd();


	glFlush();
}


void drawPoint(float x, float y) 
{ 
    glPointSize(7.0); 
    glColor3f(1.0f, 0.0f, 0.0f); 
    glBegin(GL_POINTS); 
    glVertex2f(x, y); 
    glEnd(); 
} 

void drawLine(float x1, float y1,float x2, float y2) 
{ 
	//cout << "this is new rotate line"<<endl;
    glPointSize(7.0); 
    //glColor3f(0.0f, 0.0f, 1.0f); 
    glBegin(GL_LINES); 
    glVertex2f(x1, y1); 
	glVertex2f(x2, y2); 
    glEnd(); 
} 

void ObjectMovment :: DrawPointFunction()
{
	drawAxis();
	
	//glClear(GL_COLOR_BUFFER_BIT);
	//glLoadIdentity();

	glColor3d(0.0, 0.0, 0.0);

	glPointSize(10.0);

	glBegin(GL_POINTS);
	//vertex

	for (int i = 0; i < this->rowSize; i++)
		glVertex2f(this->points[i][0],this->points[i][1]);
	 

	glEnd();

	glFlush();


}

void ObjectMovment :: DrawLineFunction()
{
	drawAxis();

	//cout << "this is draw line function"<<endl;
	//
	//glClear(GL_COLOR_BUFFER_BIT);
	//glLoadIdentity();

	glColor3d(0.0, 0.0, 1.0);

	//glLineWidth(5.0);

	
	//vertex

	//point draw
	for (int i = 0; i < this->rowSize; i++)		
		drawPoint(this->points[i][0],this->points[i][1]);
		

	float x1,x2,y1,y2,m,x_tem,y_tem;

	x1 = this->points[0][0];
	x2 = this->points[1][0];
	y1 = this->points[0][1];
	y2 = this->points[1][1];



	m = (y2-y1)/(x2-x1);

	cout << x1<<","<<y1<<","<<x2<<","<<y2<<","<<m<<","<<abs(m)<<endl;

	float x_previous_param = int(x1);
	float y_previous_param = int(y1);

	if(abs(m)>1.0)
	{
		while (y1 < y2)
		{
			y_tem =  y1 + 1;
			x_tem = x1 + 1/m;


			float x_param = int (x_tem + .5);
			
			cout << x_param<<"--"<<y_tem<<endl;

			//drawLine( x_tem,y_tem,x1,y1);

			drawLine( x_param,y_tem,x_previous_param,int(y1));

			//drawLine( int (x_tem + .5),int (y_tem + .5),int(x1),int(y1));

			x1 = x_tem ;
			y1 = y_tem;
			x_previous_param = x_param;
		}

		//x1+1 = 1/m + x1;
	}
	else
	{
		while (x1 < x2)
		{
			y_tem = m + y1;
			x_tem = x1 + 1;

			//x_tem = int (x_tem + .5);
			//y_tem = int (y_tem + .5);

			float y_param = int (y_tem + .5);

			cout << x_tem<<"--"<<y_tem<<endl;

			drawLine( x_tem, y_param ,x1,y_previous_param);

			x1 = x_tem;
			y1 = y_tem;
			y_previous_param = y_param;
		}
		//yi+1 = m+ yi;
	}




	//line draw
	/*for (int i = 0; i < this->rowSize; i+=2)
	{
		glBegin(GL_LINES);
		glVertex2f(this->points[i][0],this->points[i][1]);
		glVertex2f(this->points[i+1][0],this->points[i+1][1]);
		glEnd();
	}*/

	


	glEnd();

	glFlush();

}




void ObjectMovment :: pointPlot()
{
	int argc = 1;
	char *argv[1] = {(char*)"Something"};

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50, 100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Open GL");
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 200.0, 0.0, 150.0);
	//glutDisplayFunc(lineSegment);

	glutDisplayFunc(DrawPointFunctionSet);
	
	//glutDisplayFunc(drawAxis);
	glutReshapeFunc(reshapePoint);
	glutMainLoop();
}



void ObjectMovment :: linePlot()
{
	int argc = 1;
	char *argv[1] = {(char*)"Something"};

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50, 100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Open GL");
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 200.0, 0.0, 150.0);
	//glutDisplayFunc(lineSegment);

	glutDisplayFunc(DrawLineFunctionSet);
	
	//glutDisplayFunc(drawAxis);
	glutReshapeFunc(reshapeLine);
	glutMainLoop();
}





ObjectMovment point;

ObjectMovment line;



int main()
{
	float dot[][2] = {
		1,1,6,5
		
	};

	//point.setNecessaryPointValue(10,10,4.0,6.0,(float*)dot,(sizeof(dot)/sizeof(dot[0])),(sizeof(dot[0])/sizeof(dot[0][0])),1.0,1.0);

	//point.pointPlot();

	line.setNecessaryLineValue(12,12,4.0,6.0,(float*)dot,(sizeof(dot)/sizeof(dot[0])),(sizeof(dot[0])/sizeof(dot[0][0])),45);

	line.linePlot();

	//line.printPoint((sizeof(dot)/sizeof(dot[0])),(sizeof(dot[0])/sizeof(dot[0][0])));



	//cout << "this is main function"<<endl;

	getch();
	return 0;
}




void  reshapePoint(int w, int h)
{
	//view port v
	//porjection

	glViewport(0,0,(GLsizei)w,(GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-point.x_axis,point.x_axis,-point.y_axis,point.y_axis);
	//gluPerspective(60,1,2.0,50.0);//angle,ratio,z_near,z_far
	glMatrixMode(GL_MODELVIEW);
}


void  reshapeLine(int w, int h)
{
	//view port v
	//porjection

	glViewport(0,0,(GLsizei)w,(GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-line.x_axis,line.x_axis,-line.y_axis,line.y_axis);
	//gluPerspective(60,1,2.0,50.0);//angle,ratio,z_near,z_far
	glMatrixMode(GL_MODELVIEW);
}



void DrawPointFunctionSet()
{
	point.DrawPointFunction();
}

void DrawLineFunctionSet()
{
	line.DrawLineFunction();
}
