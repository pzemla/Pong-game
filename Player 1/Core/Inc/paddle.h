#ifndef __PADDLE_H__
#define __PADDLE_H__
#endif

#ifndef DEFINITIONS_H_
#define DEFINITIONS_H_
#include "definitions.h"
#endif

#include "stm32f4xx_hal.h"

extern ADC_HandleTypeDef JOYSTICKS_ADC;

int calculateTilt(uint32_t var);
void calculateJoystickTilt(int *joystick_tilt);
void movePaddleX(player *p, int joystick_tilt);
void movePaddleY(player *p, int joystick_tilt);
void movePlayersPaddles(player *p1, player *p2);
