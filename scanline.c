#include <GL/glut.h>
#include <stdio.h>
int flag=0;
float x1=200,y1=200,x2=100,y2=300,x3=200,y3=400,x4=300,y4=300;
int i,le[500],re[500];
float mx,x;
void  init(){
 gluOrtho2D(0,500,0,500);
}
void edgedetect(float x1,float y1,float x2,float y2){
	int i;
	float x;
	if(y2!=y1){
		mx=(x2-x1)/(y2-y1);
	}
	x=x1;	
	for(i=y1;i<=y2;i++){
		if(x<le[i])
			le[i]=(int)x;
		if(x>re[i])
			re[i]=(int)x;
		x=x+mx;		
	}
}


void scanfill(){
	int i,y;
	for(i=0;i<500;i++){
		le[i]=500;
		re[i]=0;
	}

	edgedetect(x1,y1,x2,y2);
	edgedetect(x1,y1,x4,y4);
	edgedetect(x2,y2,x3,y3);
	edgedetect(x4,y4,x3,y3);
	if(flag==1){
		for(y=0;y<500;y++){
			for(i=le[y];i<=re[y];i++){
				glColor3f(1,0,0);			
				glBegin(GL_POINTS);
						glVertex2i(i,y);	
				glEnd();
			}
		}
	}
	
}






 void display(){
 
	 glClearColor(1,1,1,0);
	 glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,0,0);
	glBegin(GL_LINE_LOOP);
		glVertex2f(x1,y1);
		glVertex2f(x2,y2);
		glVertex2f(x3,y3);
		glVertex2f(x4,y4);
	glEnd();
	scanfill();
	  
	 glFlush();
}
void menu(int id){
	if(id==1)
		flag=1;
	if(id==2)
		exit(0);
	display();
}


int main(int argc ,char **argv)
{
 
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_RGB |GLUT_SINGLE);
 glutInitWindowSize(500,500);
 glutCreateWindow("Scan Line");
 
 init();

 glutDisplayFunc(display);
 glutCreateMenu(menu);
 glutAddMenuEntry("fill",1);
 glutAddMenuEntry("exit",2);
 glutAttachMenu(GLUT_RIGHT_BUTTON);


 glutMainLoop();
 return 0;
}
