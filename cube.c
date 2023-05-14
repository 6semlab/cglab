#include<GL/glut.h>
#include<stdio.h>
#include<math.h>

float v[8][3]={{-1,-1,-1},{-1,1,-1},{1,1,-1},{1,-1,-1},{-1,-1,1},{-1,1,1},{1,1,1},{1,-1,1}};
float angle[3]={0,0,0};
int axis=0;

void polygon(int a,int b,int c,int d){
	glBegin(GL_POLYGON);
	glVertex3f(v[a][0],v[a][1],v[a][2]);
	glVertex3f(v[b][0],v[b][1],v[b][2]);
	glVertex3f(v[c][0],v[c][1],v[c][2]);
	glVertex3f(v[d][0],v[d][1],v[d][2]);
	glEnd();
}

void cube()
{
	glColor3f(1,0,0);
	polygon(0,1,5,4);
	
	glColor3f(0,1,0);
	polygon(2,6,7,3);
	
	glColor3f(0,0,1);
	polygon(0,3,7,4);
	
	glColor3f(1,1,0);
	polygon(1,2,6,5);
	
	glColor3f(1,0,1);
	polygon(0,1,2,3);
	
	glColor3f(0,1,1);
	polygon(4,5,6,7);
	
}
	
void display()
{
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();
	glRotatef(angle[0],1,0,0);
	glRotatef(angle[1],0,1,0);
	glRotatef(angle[2],0,0,1);
	
	cube();
	
	glutSwapBuffers();
	glFlush();
	
}
void init()
{
	glMatrixMode(GL_PROJECTION);
	glOrtho(-2,2,-2,2,-2,2);
	glMatrixMode(GL_MODELVIEW);
}

void spin()
{
	angle[axis]++;
	if(angle[axis]>=360) angle[axis]=0;
	display();
}

void mouse(int button,int state,int x,int y)
{
	if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN) axis=0;
	if(button==GLUT_MIDDLE_BUTTON && state==GLUT_DOWN) axis=1;
	if(button==GLUT_RIGHT_BUTTON && state==GLUT_DOWN) axis=2;
}	



int main(int argc,char **argv)
{
	
	
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE|GLUT_DEPTH);
	
	
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Cube- 1CR20CS089");
	init();
	glutDisplayFunc(display);
	
	glutMouseFunc(mouse);
	glutIdleFunc(spin);
	glEnable(GL_DEPTH_TEST);
	
	
	glutMainLoop();
	return 0;
}
