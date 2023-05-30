#ifndef __GAME_H__
#define __GAME_H__
#endif

#ifndef DEFINITIONS_H_
#define DEFINITIONS_H_
#include "definitions.h"
#endif

#include "stm32f4xx_hal.h"

//#include "display.h"
//#include "math.h"

extern TIM_HandleTypeDef GAME_TIMER;
extern TIM_HandleTypeDef PADDLE_TIMER;
extern ADC_HandleTypeDef JOYSTICKS_ADC;


void doGameTick(ball *b, player *p1, player *p2);
void wallBounce(ball *b);
void paddleBounce(ball *b, player *p1, player *p2);
void calculatePaddleBounce(ball *b, player* p, int direction);
void updateBall(ball *b);
void calculateBallPosition(ball *b);
void restartGame(ball *b, player *p1, player *p2);
void resetGameData(ball *b, player *p1, player *p2);
void gameOver(ball *b);
void startGameTicks();
void stopGameTicks();
int calculateTilt(uint32_t var);
void movePaddleX(player *p, int joystick_tilt);
void movePaddleY(player *p, int joystick_tilt);
void calculateJoystickTilt(int *joystick_tilt);
void movePlayersPaddles(player *p1, player *p2);
