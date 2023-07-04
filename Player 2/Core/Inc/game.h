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
extern UART_HandleTypeDef BLUETOOTH;


void doGameTick(ball *b);
void restartGame(ball *b, player *p1, player *p2);
void resetGameData(ball *b, player *p1, player *p2);
void gameOver(ball *b);
void startGameTicks();
void stopGameTicks();
int calculateTilt(uint32_t var);
void moveBallX(ball *b, int x);
void moveBallY(ball *b, int y);
void movePlayersPaddles(player *p1, player *p2);
void movePaddleX(player *p, int joystick_tilt);
void movePaddleY(player *p, int joystick_tilt);
void calculateJoystickTilt();
void startBluetooth();

void movePaddleUpY(player *p, int y);
void movePaddleDownY(player *p, int y);
void movePaddleDownX(player *p, int x);
void movePaddleUpX(player *p, int x);

void moveBallUpY(ball *b, int y);
void moveBallDownY(ball *b, int y);
void moveBallDownX(ball *b, int x);
void moveBallUpX(ball *b, int x);
