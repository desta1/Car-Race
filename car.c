#include <GL/glut.h>
#include<unistd.h>
#include<stdbool.h>
#include<string.h>
#define y1 y1_
int score,exit1=0;
float x,y;
float x1,y1=1000,x2=200,x3=-200,y2=1500,y3=2000;
void OpositeCar(float a,float b)
{	
	glBegin(GL_QUADS);
	glBegin(GL_QUADS);
	glColor3f(0,0,1);
	glVertex2f(-75+a,50+b);
	glVertex2f(-75+a,100+b);
	glVertex2f(75+a,100+b);
	glVertex2f(75+a,50+b);  
	glVertex2f(-75+a,150+b);
	glVertex2f(-75+a,200+b);
	glVertex2f(75+a,200+b);
	glVertex2f(75+a,150+b);
	glColor3f(1,0,0);
	glVertex2f(-25+a,50+b);
	glVertex2f(-25+a,250+b);
	glVertex2f(25+a,250+b);
	glVertex2f(25+a,50+b);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1,0,0);
	glVertex2f(-35+a,100+b);
	glVertex2f(-35+a,150+b);
	glVertex2f(35+a,150+b);
	glVertex2f(35+a,100+b);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1,1,0);
	glVertex2f(-75+a,200+b);
	glVertex2f(-25+a,250+b);
	glVertex2f(-25+a,200+b);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(75+a,200+b);
	glVertex2f(25+a,250+b);
	glVertex2f(25+a,200+b);
	glEnd();
}
void displayText(char *s){
	if (s && strlen(s)) {
     	 while (*s) {
       	  glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, *s);
       	  s++;
      }
   }

}
void displayMenu(int b, int p1)
{
	
	int i,j,k;
	i=b/100;
	j=b/10-i*10;
	k=b-j*10-i*100;
	glPushMatrix();
	if(exit1==1)
		glColor3f(0,0,0);
	else
		glColor3f(1,1,1);

	glTranslated(-400,900,0);
	glScaled(.2,.2,0);
	displayText("SCORE");
	glPopMatrix();
	glPushMatrix();
	if(exit1==1)
		glColor3f(0,0,0);
	else
		glColor3f(1,1,1);
	glTranslated(-400,850,0);
	glScaled(.2,.2,0);
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)i+48);
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)j+48);
	glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN,(int)k+48);
	glPopMatrix();


	char a[10][100];
	strcpy(a[0],"use down arrow to slow down");	
	strcpy(a[1],"use upper arrow to accelerate");
	strcpy(a[2],"use L-Arrow or R-Arrow to move L-R");	
	strcpy(a[3],"****Controls****");
	strcpy(a[4],"press SPACE to Resume/Pause Game");
	strcpy(a[5],"press s to start Game ");
	strcpy(a[6],"press q to quit the Game");
	strcpy(a[7],"****Rules for Game****");
	strcpy(a[8],"******Main Menu******");
	int ycordinate=400;
	for(int i=0;i<10;i++){
		glPushMatrix();
		glLineWidth(2);
		if(p1==0)
		glColor3f(0,0,0);
		else
		glColor3f(1,1,1);
		glTranslated(-250,ycordinate+i*50,0);
		glScaled(.15,.15,0);
		displayText(a[i]);
		glPopMatrix();
	}
}
void myCar(float a,float b)
{
	
	glBegin(GL_QUADS);
	glColor3f(0,0,1);
	glVertex2f(-75+a,50+b);
	glVertex2f(-75+a,100+b);
	glVertex2f(75+a,100+b);
	glVertex2f(75+a,50+b);
	glVertex2f(-75+a,150+b);
	glVertex2f(-75+a,200+b);
	glVertex2f(75+a,200+b);
	glVertex2f(75+a,150+b);
	glColor3f(1,1,0);
	glVertex2f(-25+a,50+b);
	glVertex2f(-25+a,250+b);
	glVertex2f(25+a,250+b);
	glVertex2f(25+a,50+b);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1,1,0);
	glVertex2f(-35+a,100+b);
	glVertex2f(-35+a,150+b);
	glVertex2f(35+a,150+b);
	glVertex2f(35+a,100+b);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1,0,0);
	glVertex2f(-75+a,200+b);
	glVertex2f(-25+a,250+b);
	glVertex2f(-25+a,200+b);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(75+a,200+b);
	glVertex2f(25+a,250+b);
	glVertex2f(25+a,200+b);
	glEnd();
	
}
void display()
{
	if(exit1==0)
	{
		if(score<25)
		{
			y=y+1;
			y1=y1-3;
			y2=y2-3;
			y3=y3-3;
		}
		if(score>=25&&score<50)
		{	
			y=y+1;
			y1-=4;
			y2-=4;
			y3-=4;
		}
		if(score>=50)
		{
			y1-=5;
			y2-=5;
			y3-=5;
		}
		//
		if(y1<-250)
		{
			score+=5;
			y1=1000;
		}
		if(y2<-250)
		{
			if(score>30)
				score += 2;
			if(score>50)
				score += 2;
						
			score+=5;
			y2=1500;
		}
		if(y3<-250)
		{
			if(score>30)
				score += 2;
			if(score>50)
				score += 2;
						
			score+=5;
			y3=2000;
		}
		if(x<-220||x>220)exit1=1;
		if(y<-50 || y>750)exit1=1;
		if(75+x>-80&&-75+x<80)
			if(200+y>y1&&200+y1>y)
				exit1=1;
		if(75+x>-280&&-75+x<-120)
			if(200+y>y3&&200+y3>y)
				exit1=1;
		if(75+x>120&&-75+x<280)
			if(200+y>y2&&200+y2>y)
				exit1=1;
		glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(0.55f,0,0.75f);
		glBegin(GL_QUADS);
		glVertex2f(-300,0);
		glVertex2f(-300,2000);
		glVertex2f(-2000,2000);
		glVertex2f(-2000,0);
	
		glVertex2f(300,0);
		glVertex2f(300,2000);
		glVertex2f(2050,2050);
		glVertex2f(2000,0);
		glEnd();
		int sug=0;
		displayMenu(score,sug);
		OpositeCar(x1,y1);
		OpositeCar(x2,y2);
		OpositeCar(x3,y3);
		myCar(x,y);
		glutSwapBuffers();
	}
	else if(exit1==1)
	{
		glClearColor(1,1,1,1);
		glClear(GL_COLOR_BUFFER_BIT);
		displayMenu(score,1);
		char a[10][100];
		strcpy(a[0],"GAMEOVER");
		strcpy(a[1],"By");
		strcpy(a[2],"Sugreev Prasad (IIT2014050 )");
		strcpy(a[3],"Rajeshwar Rao (IIT2014055) ");
		strcpy(a[4],"Shubham Jha (IIT2014037) ");
		strcpy(a[5],"IIIT ALLAHABAD ");
		int ycordinate=800;
		for(int i=0;i<=5;i++){
			glPushMatrix();
			glLineWidth(2);
			glColor3f(1,0,0);
			if(i==0){
				glTranslated(-250,900,0);
				glScaled(.6,.6,0);
			}
			else{
			glTranslated(-290,ycordinate-i*100,0);
			glScaled(.2,.2,0);
			}
			displayText(a[i]);
			glPopMatrix();
		}
		glClearColor(1,1,1,1);
		glutSwapBuffers();
		
	}
}
void keyboards(unsigned char keys,int x4,int y4)
{
	if(keys==' ')
	{
		if(exit1==0)
		exit1=2;
		else
		exit1=0;
	}
	//to quit
	if(keys=='q'||keys=='Q')
	{
		exit(-1);
	}
	//to start
	if(keys=='s' || keys=='S')
	{	
		x=0,y=0;
		x1=0,y1=1000,x2=200,x3=-200,y2=1500,y3=2000;
		exit1=0,score=0;
		glClearColor(0,0,0,0);
		glutIdleFunc(display);
	}
}
void specialKeyPress(int keys , int x4, int y4)
{
	switch (keys)
	{
		case GLUT_KEY_UP:
			y=y+20;
			break;
		case GLUT_KEY_DOWN:
			y=y-20;
			break;
		case GLUT_KEY_LEFT:
			x=x-20;
			break;
		case GLUT_KEY_RIGHT:
			x=x+20;
			break;
			
	}
}
int main(int argc, char **argv)
{
	glutInit(&argc,argv);

	glutInitWindowSize(700,1000);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutCreateWindow("Car Race In OpenGL");
	glClearColor(1,1,1,1);//set Background
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboards);
	glutSpecialFunc(specialKeyPress);
	gluOrtho2D(-400,300,0,1000);
	glutMainLoop();
	return 0;
}

