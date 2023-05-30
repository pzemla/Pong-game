#include "game.h"
#include "display.h"

#ifndef MATH_H_
#define MATH_H_
#include "math.h"
#endif

#ifndef STDLIB_H_
#define STDLIB_H_
#include <stdlib.h>
#endif

void doGameTick(ball *b, player *p1, player *p2)
{
	wallBounce(b);
	paddleBounce(b, p1, p2);
	updateBall(b);
}

void wallBounce(ball *b)
{
	if(b->x<=3 || 125<=b->x) //check wall bounce
	{
		b->vector_x = -b->vector_x;
	}
}

void paddleBounce(ball *b, player *p1, player *p2)
{
	if(b->y<=p1->y+11 && abs(b->x-p1->x)<=23) //player 1 paddle bounce
	{
		calculatePaddleBounce(b, p1, 1);
	}
	else if(p2->y<=b->y && abs(b->x-p2->x)<=23) //player 2 paddle bounce
	{
		calculatePaddleBounce(b, p2, -1);
	}
}

void calculatePaddleBounce(ball *b, player* p, int direction)
{
	b->vector_x = sin((p->x-b->x_f)/20*60*M_PI/180)*(-1);
	b->vector_y = cos((p->x-b->x_f)/20*60*M_PI/180)*direction;
}

void updateBall(ball *b)
{
	eraseBall(b->x-3, b->y-6);
    calculateBallPosition(b);
    drawBall(b->x-3, b->y-6);
}

void calculateBallPosition(ball *b)
{
    b->x_f = b->x_f+b->vector_x;
    b->y_f = b->y_f+b->vector_y;

    b->x = round(b->x_f);
    b->y = round(b->y_f);
}

void restartGame(ball *b, player *p1, player *p2)
{
	stopGameTicks();
	clearDisplay();
	resetGameData(b, p1, p2);
	drawNewGame();
	HAL_Delay(500);
	startGameTicks();
}

void resetGameData(ball *b, player *p1, player *p2)
{
	p1->x=64;
	p1->y=0;
	p1->y_min=0;
	p1->y_max=10;
	p2->x=64;
	p2->y=155;
	p2->y_min=145;
	p2->y_max=155;
	b->x = 64;
	b->y = 77;
	b->x_f = 64;
	b->y_f = 77;
	b->vector_x = 0;
	b->vector_y = 1;
}

void gameOver(ball *b)
{
	stopGameTicks();
	drawGameOver();
}

void startGameTicks()
{
	HAL_TIM_Base_Start_IT(&PADDLE_TIMER);
	HAL_TIM_Base_Start_IT(&GAME_TIMER);
}

void stopGameTicks()
{
	HAL_TIM_Base_Stop_IT(&PADDLE_TIMER);
	HAL_TIM_Base_Stop_IT(&GAME_TIMER);
}

int calculateTilt(uint32_t var){
	return (int)round(10.0*((var-2048.0)/4096.0)); //przy większych czułościach zamiast 2048 powinien być
}                                                  //średni odczytany adc_value przy 0 przechyleniu

void movePaddleX(player *p, int joystick_tilt){
	if(joystick_tilt!=0){
		int paddle_direction_x = (joystick_tilt>0) ? 0 : 1;
	    int paddle_signum = (joystick_tilt>0) ? 1 : -1;
	    int paddle_limit_x = (p->x+joystick_tilt>=20) ? joystick_tilt : 20-p->x;
		paddle_limit_x = (108>=p->x+joystick_tilt) ? paddle_limit_x : 108-p->x;

		ST7735_FillRectangleFast(p->x-paddle_signum*20+paddle_direction_x*paddle_limit_x, p->y, abs(paddle_limit_x), 5, ST7735_BLACK);
		ST7735_FillRectangleFast(p->x+paddle_signum*20+paddle_direction_x*paddle_limit_x, p->y, abs(paddle_limit_x), 5, ST7735_WHITE);
		p->x=p->x+paddle_limit_x;}
}

void movePaddleY(player *p, int joystick_tilt){
	if(joystick_tilt!=0){
		    	int paddle_direction_y = (0>joystick_tilt) ? 1 : 0;
		    	int paddle_limit_y = (p->y+joystick_tilt>=p->y_min) ? joystick_tilt : p->y_min-p->y;
		    	paddle_limit_y = (p->y_max>=p->y+joystick_tilt) ? paddle_limit_y : p->y_max-p->y;

		        ST7735_FillRectangleFast(p->x-20, p->y+(5+paddle_limit_y)*paddle_direction_y, 40, abs(paddle_limit_y), ST7735_BLACK);
		    	ST7735_FillRectangleFast(p->x-20, p->y+paddle_limit_y, 40, abs(paddle_limit_y), ST7735_WHITE);
		    	p->y=p->y+paddle_limit_y;}
}

void calculateJoystickTilt(int *joystick_tilt){
	uint32_t adc_value[4];
    for (int i = 0; i < 4; i++) {
		HAL_ADC_Start(&JOYSTICKS_ADC);
	    HAL_ADC_PollForConversion(&JOYSTICKS_ADC, 480);
    	adc_value[i] = HAL_ADC_GetValue(&JOYSTICKS_ADC);
    	joystick_tilt[i] = calculateTilt(adc_value[i]);
    }
}

void movePlayersPaddles(player *p1, player *p2){
	int joystick_tilt[4];
	calculateJoystickTilt(joystick_tilt);
	movePaddleX(p1,joystick_tilt[0]);
	movePaddleY(p1,joystick_tilt[1]);
	movePaddleX(p2,joystick_tilt[2]);
	movePaddleY(p2,joystick_tilt[3]);
}
