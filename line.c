#include<GL/glut.h>
 void init()
{
	glClearColor(1,1,1,0);
	glClear(GL_COLOR_BUFFER_BIT);
	gluOrtho2D(0,500,0,500);
	
}
void draw_pixel(int x,int y)
{
	glColor3d(1,0,0);
	glBegin(GL_POINTS);
	glVertex2d(x,y);
	glEnd();
}

void bresenhams(int x1,int y1,int x2,int y2)
{
	int dx,dy,i,p,x,y,incx,incy;
	dx=abs(x2-x1);
	dy=abs(y2-y1);
	incx=1;
	if(x1>x2)
		incx=-1;
	incy=1;
	if(y1>y2)
		incy=-1;
	x=x1; y=y1;
	
	if(dx>=dy)
	{	
		draw_pixel(x,y);
		p=2*dy-dx;
		for(i=0;i<dx;i++)
		{
			x=x+incx;
			if(p<0)
				p+=2*dy;
			else
			{
				p+=2*dy-2*dx;
				y=y+incy;
			}
			draw_pixel(x,y);
		}
	}
	else
	{	draw_pixel(x,y);
		p=2*dx-dy;
		for(i=0;i<dy;i++)
		{
			y+=incy;
			if(p<0)
				p+=2*dx;
			else
			{
				p+=2*dx-2*dy;
				x+=incx;
			}
			draw_pixel(x,y);
		}
	}	
}

					
void display()
{ 
	                                                                                                                                                                                                                                                                                                                                                
	bresenhams(10,60,450,100);	
	glFlush();
}

int main(int argc,char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	
	glutCreateWindow("Line Drawing Algorithm");
	glutInitWindowSize(500,500);
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
