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
	int y_max;
	int y_min;
} player;

typedef struct ball{
	int x;
	int y;
	float x_f;
	float y_f;
	double vector_x;
	double vector_y;
} ball;
