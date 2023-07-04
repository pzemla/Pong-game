#include "display.h"
#ifndef _DEFINITIONS_H_
#include "definitions.h"
#endif

#define PADDLE_HEIGHT 5

void eraseBall(int x, int y)
{
	ST7735_FillRectangleFast(x, y, 6, 6, ST7735_BLACK);
}

void drawBall(int x, int y)
{
	ST7735_FillRectangleFast(x, y, 6, 6, ST7735_WHITE);
}

void clearDisplay()
{
	ST7735_FillScreenFast(ST7735_BLACK);
}

void drawNewGame()
{
	ST7735_FillRectangleFast(44, 0, 40, PADDLE_HEIGHT, ST7735_WHITE); 	//p1
	ST7735_FillRectangleFast(44, 155, 40, PADDLE_HEIGHT, ST7735_WHITE); 	//p2
	ST7735_FillRectangleFast(61, 71, 6, 6, ST7735_WHITE); 	//ball
}

void drawGameOver()
{
	 ST7735_FillScreen(ST7735_MAGENTA);
	 ST7735_WriteString(15, 80, "GAME OVER", Font_11x18, ST7735_WHITE, ST7735_MAGENTA);
}

void drawMovePaddle(int player, int current_position, int distance, int direction)
{
	int y;
	if(player == 1) y = 0; //player 1 paddle is at y = 0
	else y = 155;		   //player 2 paddle is at y = 155


	if(direction == 1)	//moving to x+
	{
		ST7735_FillRectangleFast(current_position-20, y, distance, PADDLE_HEIGHT, ST7735_BLACK);
		ST7735_FillRectangleFast(current_position+20, y, distance, PADDLE_HEIGHT, ST7735_WHITE);
	}
	else				//moving to x-
	{
		ST7735_FillRectangleFast(current_position+20-distance, y, distance, PADDLE_HEIGHT, ST7735_BLACK);
		ST7735_FillRectangleFast(current_position-20-distance, y, distance, PADDLE_HEIGHT, ST7735_WHITE);
	}
}
