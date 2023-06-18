#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
float xmax=100.0,ymax=100.0,xmin=50.0,ymin=50.0;

int left=8,right=4,bottom=2,top=1;
 void init()
{
	glClearColor(1,1,1,0);
	glClear(GL_COLOR_BUFFER_BIT);
	gluOrtho2D(0,500,0,500);
	
}

void drawClipWindow(){
	glBegin(GL_LINE_LOOP);
	
	glVertex2f(xmin,ymin);
	glVertex2f(xmin,ymax);
	glVertex2f(xmax,ymax);
	glVertex2f(xmax,ymin);
	glEnd();
}
void drawLine(float x0,float y0,float x1,float y1){
	glBegin(GL_LINES);
	glVertex2f(x0,y0);
	glVertex2f(x1,y1);
	glEnd();
	}
int outcode(float x,float y){
	int code=0;
	if(y>ymax)
		code=code|top;
	if(y<ymin)
		code=code|bottom;
	if(x>xmax)
		code=code|right;
	if(x<xmin)
		code=code|left;
	return code;
}

void cohen(float x0,float y0,float x1,float y1){
	int p0=outcode(x0,y0);
	int p1=outcode(x1,y1);
	int out,accept=0,done=0;
	float x,y;
	do{
		printf("\n%f %f %f %f",x0,y0,x1,y1);
		//trivial
		if((p0|p1) ==0)
		{
			done=1;
			accept=1;
		}
		else if(( p0 & p1) !=0)
			done=1;
		else{
			if(p0!=0)
			out=p0;
			else
				out=p1;
			if(out & top){
				y=ymax;
				x=x0+(ymax-y0)*(x1-x0)/(y1-y0);
				
			}
			else if(out&bottom){
				y=ymin;
				x=x0+(ymin-y0)*(x1-x0)/(y1-y0);
			}
			if(out&left){
				x=xmin;
				y=y0+(xmin-x0)*(y1-y0)/(x1-x0);
				
			}
			else if(out&right){
				x=xmax;
				y=y0+(xmax-x0)*(y1-y0)/(x1-x0);
			}
			
			if(out==p0){
				x0=x;
				y0=y;
				p0=outcode(x0,y0);
			}
			else{
				x1=x;
				y1=y;
				p1=outcode(x1,y1);
			}
			}
		}while(done==0);
		if(accept){
		
			
			glColor3f(1,0,0);
			glPushMatrix();
			glTranslated(150,150,0);
			drawClipWindow();
			drawLine(x0,y0,x1,y1);
			glPopMatrix();
		}
}
			
						
			
	
void display()
{ 
				
	                                                                                                                                                                                                                                                                                                                                                  
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0,0,1);
	drawClipWindow();
	float x0=120,y0=10,x1=40,y1=130;
	drawLine(x0,y0,x1,y1);
	cohen(x0,y0,x1,y1);
	
	glFlush();
}



int main(int argc,char **argv)
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	
	glutCreateWindow("Cohen Sutherland");
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	
	init();
	glutDisplayFunc(display);
	
	
	glutMainLoop();
	return 0;
}
