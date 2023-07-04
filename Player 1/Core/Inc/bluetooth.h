#ifndef __BLUETOOTH_H_
#define __BLUETOOTH_H_
#endif

#ifndef DEFINITIONS_H_
#define DEFINITIONS_H_
#include "definitions.h"
#endif

#include "stm32f4xx_hal.h"

extern UART_HandleTypeDef BLUETOOTH;

void startBluetooth();
void stopBluetooth();
void convertPaddlesToChar(player *p1, player *p2);
void convertBallToChar(ball *b);
