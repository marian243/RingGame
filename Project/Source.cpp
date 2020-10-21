#define _CRT_SECURE_NO_WARNINGS
#include "iGraphics.h"

int crle1x = 50, crle1y = 550, crl1p = 0;
int crle2x = 370, crle2y = 430, crl2p = 0;
int crle3x = 750, crle3y = 310, crl3p = 0;
int ball_x = 400, ball_y = 50, ball_p = 0;
int pnts = 0, life = 3, start = 0, hit = 0;
char point[100], rem_ball[10];


void ball()
{
	if (ball_p == 1)
	{
		ball_y += 15;
		if (ball_y >= 600)
		{
			ball_p = 0;
			ball_x = (rand() % 700) + 10;
			ball_y = 50;
			life--;
		}
	}
	if (((ball_x > crle3x - 30 && ball_x < crle3x + 30) && (ball_y+10 > crle3y)) && life>0)
	{
		pnts += 3;
		ball_p = 0;
		ball_x = (rand() % 700) + 10;
		ball_y = 50;
	}

	else if (((ball_x > crle2x - 30 && ball_x < crle2x + 30) && (ball_y > crle2y - 30)) && life>0)
	{
		pnts += 2;
		ball_p = 0;
		ball_x = (rand() % 700) + 10;
		ball_y = 50;
	}

	else if (((ball_x > crle1x - 40 && ball_x < crle1x + 40) && (ball_y > crle1y - 40)) && life>0)
	{
		pnts++;
		ball_p = 0;
		ball_x = (rand() % 700) + 10;
		ball_y = 50;
	}
}


void circle_move()
{
	if (crl1p == 0)
	{
		crle1x += 5;
		if (crle1x > 750)
			crl1p = 1;                     //first circle
	}
	if (crl1p == 1)
	{
		crle1x -= 5;
		if (crle1x < 50)
			crl1p = 0;
	}
	

	if (crl2p == 0)
	{
		crle2x -= 7;
		if (crle2x < 50)                      //second circle
			crl2p = 1;
	}
	if (crl2p == 1)
	{
		crle2x += 7;
		if (crle2x > 750)
			crl2p = 0;
	}

	if (crl3p == 0)
	{
		crle3x += 9;
		if (crle3x > 750)
			crl3p = 1;
	}                                      //third circle
	if (crl3p == 1)
	{
		crle3x -= 9;
		if (crle3x < 50)
			crl3p = 0;
	}
}

void iDraw()
{
	iClear();
	if (start == 0)
	{
		iPauseTimer(0);
		iShowBMP(0, 0, "Untitled2.bmp");
		iSetColor(128, 0, 0);                                               //start screen
		iText(300, 200, "Press M to begin", GLUT_BITMAP_TIMES_ROMAN_24);
	}
	else if (start == 1)
	{
		iShowBMP(0, 0, "Photo.bmp");
		iSetColor(255, 0, 0);
		iFilledCircle(crle1x, crle1y, 45);
		iSetColor(255, 255, 255);
		iFilledCircle(crle1x, crle1y, 30);
		iSetColor(255, 0, 0);
		iFilledCircle(crle1x, crle1y, 15);

		iSetColor(255, 0, 0);
		iFilledCircle(crle2x, crle2y, 45);
		iSetColor(255, 255, 255);
		iFilledCircle(crle2x, crle2y, 30);
		iSetColor(255, 0, 0);
		iFilledCircle(crle2x, crle2y, 15);

		iSetColor(255, 0, 0);
		iFilledCircle(crle3x, crle3y, 45);
		iSetColor(255, 255, 255);
		iFilledCircle(crle3x, crle3y, 30);
		iSetColor(255, 0, 0);
		iFilledCircle(crle3x, crle3y, 15);

		iSetColor(255, 47, 47); 
		iFilledCircle(ball_x, ball_y, 10);

		iSetColor(0, 0, 0);
		sprintf(point, "POINTS: %d", pnts);
		iText(650, 200, point, GLUT_BITMAP_TIMES_ROMAN_24);
		sprintf(rem_ball, "Remaining Life: %d", life);
		iText(620, 150, rem_ball, GLUT_BITMAP_HELVETICA_18);
		iSetColor(0, 0, 0);
		iText(550, 50, "Press Space to move the point");
		iSetColor(0, 0, 0);
		iText(550, 25, "Press A to quit");
		iResumeTimer(0);
	}
	if (life <= 0)
	{
		iPauseTimer(0);
		iShowBMP(0, 0, "go.bmp");
		iSetColor(202, 0, 5);
		sprintf(point, "POINTS: %d", pnts);
		iText(350, 250, point, GLUT_BITMAP_TIMES_ROMAN_24);                          //End screen
		iSetColor(0, 0, 0);
		iText(350, 150, "Press M to begin again", GLUT_BITMAP_HELVETICA_12);
	}

}

void iMouseMove(int mx, int my)
{

}
void iMouse(int button, int state, int mx, int my)
{
	/*if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		ball_p = 1;
	}*/
}
void iKeyboard(unsigned char key)
{
	if (key == ' ')
		ball_p = 1;

	if (key == 'm' || key == 'M')
	{
		start = 1;
		pnts = 0;
		life = 3;
	}
	if (key == 'a' || key == 'A')
		exit(0);
	
}
void iSpecialKeyboard(unsigned char key)
{
	
}
int main()
{
	iSetTimer(15, circle_move);
	iSetTimer(10, ball);
	iInitialize(800, 600, "The Ring");
	return 0;
}