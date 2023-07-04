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
void drawGameOver();
void drawMovePaddle(int player, int current_position, int distance, int direction);

