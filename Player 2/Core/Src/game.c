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

unsigned char bt_data[7];
unsigned char joystick_tilt[2];

void calculateJoystickTilt(){
	uint32_t adc_value[2];
    for (int i = 0; i < 2; i++) {
		HAL_ADC_Start(&JOYSTICKS_ADC);
	    HAL_ADC_PollForConversion(&JOYSTICKS_ADC, 480);
    	adc_value[i] = HAL_ADC_GetValue(&JOYSTICKS_ADC);
    	joystick_tilt[i] = (unsigned char)calculateTilt(adc_value[i]);
    }
}


void doGameTick(ball *b)
{
	moveBallUpY(b, (int)bt_data[5]);
	moveBallDownY(b, (int)bt_data[5]);
	moveBallDownX(b, (int)bt_data[4]);
	moveBallUpX(b, (int)bt_data[4]);
}


void restartGame(ball *b, player *p1, player *p2)
{
	stopGameTicks();
	clearDisplay();
	resetGameData(b, p1, p2);
	startBluetooth();
	drawNewGame();
	startGameTicks();
}

void startBluetooth(){
	HAL_UART_Receive_DMA(&BLUETOOTH, bt_data, sizeof(bt_data));
	HAL_UART_Transmit_DMA(&BLUETOOTH, joystick_tilt, sizeof(joystick_tilt));
}

void resetGameData(ball *b, player *p1, player *p2)
{
	p1->x=64;
	p1->y=0;
	p2->x=64;
	p2->y=155;
	b->x = 64;
	b->y = 77;
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
	return (int)round(10.0*(var/4096.0));
}

void movePlayersPaddles(player *p1, player *p2){
	movePaddleDownX(p1,(int)bt_data[0]);
	movePaddleDownY(p1,(int)bt_data[1]);
	movePaddleDownX(p2,(int)bt_data[2]);
	movePaddleDownY(p2,(int)bt_data[3]);

	movePaddleUpX(p1,(int)bt_data[0]);
	movePaddleUpY(p1,(int)bt_data[1]);
	movePaddleUpX(p2,(int)bt_data[2]);
	movePaddleUpY(p2,(int)bt_data[3]);
}


void movePaddleUpY(player *p, int y){ //x - 40, y - 5
	if(y>p->y){
		int paddle_limit_y_reached = (5>abs(y-p->y)) ? 0 : 1;
    	int paddle_limit_y = (5>abs(y-p->y)) ? abs(y-p->y) : 5;

    	ST7735_FillRectangleFast(p->x-20, p->y , 40, paddle_limit_y, ST7735_BLACK);
    	ST7735_FillRectangleFast(p->x-20, p->y+5+paddle_limit_y_reached*(y-p->y-5), 40, paddle_limit_y, ST7735_WHITE);
    	p->y=y;
	}
}

void movePaddleDownY(player *p, int y){ //x - 40, y - 5
	if(y<p->y){
    	int paddle_limit_y = (5>abs(y-p->y)) ? abs(y-p->y) : 5;

    	ST7735_FillRectangleFast(p->x-20, p->y+5-paddle_limit_y, 40, paddle_limit_y, ST7735_BLACK);
    	ST7735_FillRectangleFast(p->x-20, y, 40, paddle_limit_y, ST7735_WHITE);
    	p->y=y;
	}
}

void movePaddleDownX(player *p, int x){ //x - 40, y - 5
	if(x<p->x){
    	int paddle_limit_x = (40>abs(x-p->x)) ? abs(x-p->x) : 40;

    	ST7735_FillRectangleFast(p->x+20-paddle_limit_x, p->y, paddle_limit_x, 5, ST7735_BLACK);
    	ST7735_FillRectangleFast(x-20, p->y, paddle_limit_x, 5, ST7735_WHITE);
    	p->x=x;
	}
}

void movePaddleUpX(player *p, int x){ //x - 40, y - 5
	if(x>p->x){
		int paddle_limit_x_reached = (5>abs(x-p->x)) ? 0 : 1;
    	int paddle_limit_x = (5>abs(x-p->x)) ? abs(x-p->x) : 40;

    	ST7735_FillRectangleFast(p->x-20, p->y, paddle_limit_x, 5, ST7735_BLACK);
    	ST7735_FillRectangleFast(p->x+20+paddle_limit_x_reached*(x-p->x-40), p->y, paddle_limit_x, 5, ST7735_WHITE);
    	p->x=x;
	}
}

void moveBallUpY(ball *b, int y){
	if(y>b->y){
		int ball_limit_y_reached = (6>abs(y-b->y)) ? 0 : 1;
    	int ball_limit_y = (6>abs(y-b->y)) ? abs(y-b->y) : 6;

    	ST7735_FillRectangleFast(b->x-3, b->y-6 , 6, ball_limit_y, ST7735_BLACK);
    	ST7735_FillRectangleFast(b->x-3, b->y+ball_limit_y_reached*(y-b->y-6), 6, ball_limit_y, ST7735_WHITE);
    	b->y=y;
	}
}

void moveBallDownY(ball *b, int y){
	if(y<b->y){
    	int ball_limit_y = (6>abs(y-b->y)) ? abs(y-b->y) : 6;

    	ST7735_FillRectangleFast(b->x-3, b->y-ball_limit_y, 6, ball_limit_y, ST7735_BLACK);
    	ST7735_FillRectangleFast(b->x-3, y-6, 6, ball_limit_y, ST7735_WHITE);
    	b->y=y;
	}
}

void moveBallDownX(ball *b, int x){
	if(x<b->x){
    	int ball_limit_x = (6>abs(x-b->x)) ? abs(x-b->x) : 6;

    	ST7735_FillRectangleFast(b->x+3-ball_limit_x, b->y-6, ball_limit_x, 6, ST7735_BLACK);
    	ST7735_FillRectangleFast(x-3, b->y-6, ball_limit_x, 6, ST7735_WHITE);
    	b->x=x;
	}
}

void moveBallUpX(ball *b, int x){
	if(x>b->x){
		int ball_limit_x_reached = (6>abs(x-b->x)) ? 0 : 1;
    	int ball_limit_x = (6>abs(x-b->x)) ? abs(x-b->x) : 6;

    	ST7735_FillRectangleFast(b->x-3, b->y-6, ball_limit_x, 6, ST7735_BLACK);
    	ST7735_FillRectangleFast(b->x+3+ball_limit_x_reached*(x-b->x-6), b->y-6, ball_limit_x, 6, ST7735_WHITE);
    	b->x=x;
	}
}
