#include "display.h"
#ifndef _DEFINITIONS_H_
#include "definitions.h"
#endif

#ifndef MATH_H_
#define MATH_H_
#include "math.h"
#endif

#ifndef STDLIB_H_
#define STDLIB_H_
#include <stdlib.h>
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

void drawGameOver(uint8_t *score)
{
	 char temp[2] = "00";
	 ST7735_FillScreen(ST7735_MAGENTA);
	 ST7735_WriteString(15, 80, "GAME OVER", Font_11x18, ST7735_WHITE, ST7735_MAGENTA);
	 itoa(score[0],temp,10);
	 ST7735_WriteString(15, 120, temp, Font_11x18, ST7735_WHITE, ST7735_MAGENTA);
	 itoa(score[1],temp,10);
	 ST7735_WriteString(64+15, 120, temp, Font_11x18, ST7735_WHITE, ST7735_MAGENTA);
}

void drawPaddleMovementX(int playerX, int playerY, int paddle_direction_x, int paddle_limit_x, int paddle_signum){
	ST7735_FillRectangleFast(playerX-paddle_signum*20+paddle_direction_x*paddle_limit_x, playerY, abs(paddle_limit_x), 5, ST7735_BLACK);
	ST7735_FillRectangleFast(playerX+paddle_signum*20+paddle_direction_x*paddle_limit_x, playerY, abs(paddle_limit_x), 5, ST7735_WHITE);
}

void drawPaddleMovementY(int playerX, int playerY, int paddle_direction_y, int paddle_limit_y){
    ST7735_FillRectangleFast(playerX-20, playerY+(5+paddle_limit_y)*paddle_direction_y, 40, abs(paddle_limit_y), ST7735_BLACK);
	ST7735_FillRectangleFast(playerX-20, playerY+paddle_limit_y, 40, abs(paddle_limit_y), ST7735_WHITE);
}
