#ifndef __DEFINITIONS_H
#define __DEFINITIONS_H
#endif

#define GAME_TIMER htim10
#define PADDLE_TIMER htim11
#define JOYSTICKS_ADC hadc1
#define BLUETOOTH huart1

typedef struct player{
	int x;
	int y;
} player;

typedef struct ball{
	int x;
	int y;
} ball;
