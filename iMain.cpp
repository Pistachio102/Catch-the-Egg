#include "iGraphics.h"
#include<stdio.h>
#include<stdlib.h>
#define SPEED 2

/// variables
int bktdx, bktdy;
int mode = 0;
int picindex = 0;
int is_Gamestart = 0;
int cnt = 0;
int score = 0;
int scoretaken = 1;
int val, color;
int life = 5;
int newlife = 0;
char char_str[100];
int rong[3] = { 136, 0, 21 };

/// array variables
char pic[5][30] = { "PrPic//menu_f.bmp", "PrPic//game_b.bmp", "PrPic//dim.bmp" };
char dim[5][30] = { "PrPic//blue dim.bmp", "PrPic//yellow dim.bmp", "PrPic//pink dim.bmp", "PrPic//dim.bmp","PrPic//bomb.bmp" };
int eggcord[5][12] = { 140, 368, 330, 368, 510, 368, 690, 368, 870, 368 };
char scoreboard[30] = "SCORE: ";
int dimArray[5] = { 144, 316, 488, 660, 832 };
char scrPrint[10][30] = { "PrPic//0.bmp", "PrPic//1.bmp", "PrPic//2.bmp", "PrPic//3.bmp", "PrPic//4.bmp", "PrPic//5.bmp", "PrPic//6.bmp", "PrPic//7.bmp", "PrPic//8.bmp", "PrPic//9.bmp" };
char lifePrint[6][30] = { "PrPic//life0.bmp", "PrPic//life1.bmp", "PrPic//life2.bmp", "PrPic//life3.bmp", "PrPic//life4.bmp", "PrPic//life5.bmp" };


/// functions

void toa(int num)
{
	int num2 = num;
	char_str[0]=0;
	int len = 0, i, j;
	while (num > 0)
	{
		char_str[len++] = (num % 10) + '0';
		num /= 10;




	}
	for (i = 0,j = len - 1; i < j; i++, j--)
	{

		char tmp = char_str[i];
		char_str[i] = char_str[j];
		char_str[j] = tmp;



	}
	char_str[len] = '\0';
	if (num2 == 0)
	{
		char_str[0] = '0'; char_str[1] = '\0';


	}
}

void dimPrint()
{
	
	toa(score);
	iSetColor(0, 0, 0);
	iText(835, 428, char_str, GLUT_BITMAP_TIMES_ROMAN_24);

	iShowBMP(465, 430, lifePrint[life]);

	if (is_Gamestart == 1 && picindex == 1)
	{
		iShowBMP(dimArray[val], bktdy - SPEED*cnt, dim[color]);
	

	}

	if (bktdx <= dimArray[val] && bktdx + 102 >= dimArray[val] && (bktdy - SPEED*cnt) <= 90 && scoretaken == 1)
	{
		scoretaken = 0;
		if (color != 4){
			score++;
		}
		else{
			if (life > 0) life--;
			newlife = 0;
		}
	}

	/*else if (((bktdx > dimArray[val] || bktdx + 102 < dimArray[val]) && (bktdy-SPEED*cnt) <= 90 && newlife == 1 && is_Gamestart == 1 && color!=4) ||(bktdx <= dimArray[val] && bktdx + 102 >= dimArray[val] && (bktdy - SPEED*cnt) <= 90 && color==4 && newlife==1))
	{
		if (life > 0) life--;
		newlife = 0;
		
	}*/
	if ((bktdy - SPEED*cnt) <= 90)
	{
		cnt = 0;
		val = rand() % 5;
		scoretaken = 1;
		newlife = 1;
		color = rand() % 5;
	}
	cnt++;
}

void showbasket()
{
	if (is_Gamestart == 1 && picindex == 1)
	{
		iShowBMP(bktdx, 9, "PrPic//bkt.bmp");
	}
}


void iDraw()
{
	//place your drawing codes here
	iClear();
	iShowBMP(0, 0, pic[picindex]);
	if (mode == 1)
	{
		iSetColor(255, 255, 208);
		showbasket();
		dimPrint();
	}
	if (life == 0)
	{
		iClear();
		iShowBMP(0, 0, "PrPic//gameOver.bmp");
		iText(430, 70, scoreboard, GLUT_BITMAP_TIMES_ROMAN_24);
		
		toa(score);
		iText(530, 70, char_str, GLUT_BITMAP_TIMES_ROMAN_24);
	}

}


/*
function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
}

/*
function iMouse() is called when the user presses/releases the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	printf("%d %d\n", mx, my);
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
		bktdx = mx;
		bktdy = 360;

		if (is_Gamestart == 0 && picindex == 0 && (mx >= 368 && mx <= 640) && (my >= 40 && my <= 110) && (mode == 0))
		{
			mode = 1;
			picindex = 1;
			is_Gamestart = 1;

		}
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
}
/*iPassiveMouseMove is called to detect and use
the mouse point without pressing any button */

void iPassiveMouseMove(int mx, int my)
{
	//place your code here

}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	if (key == 'q')
	{
		//do something with 'q'
	}
	//place your codes for other keys here
}

/*
function iSpecialKeyboard() is called whenver user hits special keys like-
function keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

	if (key == GLUT_KEY_END)
	{
		exit(0);
	}
	//place your codes for other keys here
	if (is_Gamestart == 1 && picindex == 1)
	{
		if (key == GLUT_KEY_RIGHT)
		{
			if (bktdx + 10 <= 898) bktdx += 30;

		}
		if (key == GLUT_KEY_LEFT)
		{
			if (bktdx - 10 >= 0) bktdx -= 30;
		}

	}
}
//
int main()
{
	//place your own initialization codes here.
	int t = iSetTimer(500, dimPrint);
	iInitialize(1000, 600, "myiGraphics");

	return 0;
}
