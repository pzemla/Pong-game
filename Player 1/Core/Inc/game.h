#ifndef __GAME_H__
#define __GAME_H__
#endif

#ifndef DEFINITIONS_H_
#define DEFINITIONS_H_
#include "definitions.h"
#endif

#ifndef BALL_H_
#define BALL_H_
#include "ball.h"
#endif

#ifndef PADDLE_H_
#define PADDLE_H_
#include "paddle.h"
#endif

#ifndef BLUETOOTH_H_
#define BLUETOOTH_H_
#include "bluetooth.h"
#endif

#include "stm32f4xx_hal.h"

extern TIM_HandleTypeDef PADDLE_TIMER;
extern TIM_HandleTypeDef GAME_TIMER;


void doGameTick(ball *b, player *p1, player *p2);
void restartGame(ball *b, player *p1, player *p2);
void resetGameData(ball *b, player *p1, player *p2);
void gameOver(ball *b);
void startGameTicks();
void stopGameTicks();
void checkGameOver(ball *b, int *flag);
void checkRestartGame(ball *b, player *p1, player *p2, int *flag);
void saveNewScore();
int checkHighScore();
