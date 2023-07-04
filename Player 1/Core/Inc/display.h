#ifndef __DISPLAY_H__
#define __DISPLAY_H__
#endif

#ifndef ST7735_H_
#define ST7735_H_
#include "st7735.h"
#endif

void eraseBall(int x, int y);
void drawBall(int x, int y);
void clearDisplay();
void drawNewGame();
void drawGameOver(uint8_t *score);
void drawPaddleMovementX(int playerX, int playerY, int paddle_direction_x, int paddle_limit_x, int paddle_signum);
void drawPaddleMovementY(int playerX, int playerY, int paddle_direction_y, int paddle_limit_y);
