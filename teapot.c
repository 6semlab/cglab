#include<GL/glut.h>

float light_pos[]={2,2,2,1};
float ambient[]={1,1,1,1};
void align()
{
	glRotatef(50,0,1,0);
	glRotatef(10,-1,0,0);
	glRotatef(10,0,0,-1);
	}
void object(float tx,float ty,float tz,float sx,float sy,float sz)
{
	align();
	glTranslatef(tx,ty,tz);
	glScalef(sx,sy,sz);
	glutSolidCube(1);
	glLoadIdentity();
}
	
void display()
{
	
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	object(0,0,0.5,1,1,0.04);
	object(-0.5,0,0,0.04,1,1);
	object(0,-0.5,0,1,0.04,1);
	
	//legs
	object(0,-0.3,0,0.02,0.2,0.02);
	object(0,-0.3,-0.3,0.02,0.2,0.02);
	object(0.3,-0.3,-0.3,0.02,0.2,0.02);
	object(0.3,-0.3,0,0.02,0.2,0.02);
	//top
	object(0.2,-0.2,-0.2,0.6,0.02,0.6);
	//glutSwapBuffers();
	glPushMatrix();
	align();
	glTranslatef(0.3,-0.1,-0.3);
	glutSolidTeapot(0.09);
	glPopMatrix();
	glFlush();
	
}

int main(int argc,char **argv)
{
	
	
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE|GLUT_DEPTH);
	
	
	glutInitWindowSize(700,700);
	glutInitWindowPosition(0,0);
	glutCreateWindow("TeaPot");
	//init();
	glutDisplayFunc(display);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glMaterialfv(GL_FRONT,GL_AMBIENT,ambient);
	glLightfv(GL_LIGHT0,GL_POSITION,light_pos);
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
	return 0;
}
