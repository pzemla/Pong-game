#include "paddle.h"
#include "display.h"
#include "bluetooth.h"

#ifndef MATH_H_
#define MATH_H_
#include "math.h"
#endif

extern unsigned char bt_receive[];

int calculateTilt(uint32_t var){
	return (int)round(10.0*((var-2048.0)/4096.0)); //przy większych czułościach zamiast 2048 powinien być
}                                                  //średni odczytany adc_value przy 0 przechyleniu

void movePaddleX(player *p, int joystick_tilt){
	if(joystick_tilt!=0){
		int paddle_direction_x = (joystick_tilt>0) ? 0 : 1;
	    int paddle_signum = (joystick_tilt>0) ? 1 : -1;
	    int paddle_limit_x = (p->x+joystick_tilt>=20) ? joystick_tilt : 20-p->x;
		paddle_limit_x = (108>=p->x+joystick_tilt) ? paddle_limit_x : 108-p->x;

		drawPaddleMovementX(p->x, p->y, paddle_direction_x, paddle_limit_x, paddle_signum);
		p->x=p->x+paddle_limit_x;}
}

void movePaddleY(player *p, int joystick_tilt){
	if(joystick_tilt!=0){
		    	int paddle_direction_y = (0>joystick_tilt) ? 1 : 0;
		    	int paddle_limit_y = (p->y+joystick_tilt>=p->y_min) ? joystick_tilt : p->y_min-p->y;
		    	paddle_limit_y = (p->y_max>=p->y+joystick_tilt) ? paddle_limit_y : p->y_max-p->y;

		    	drawPaddleMovementY(p->x, p->y, paddle_direction_y, paddle_limit_y);
		    	p->y=p->y+paddle_limit_y;}
}

void calculateJoystickTilt(int *joystick_tilt){
	uint32_t adc_value[2];
    for (int i = 0; i < 2; i++) {
		HAL_ADC_Start(&JOYSTICKS_ADC);
	    HAL_ADC_PollForConversion(&JOYSTICKS_ADC, 480);
    	adc_value[i] = HAL_ADC_GetValue(&JOYSTICKS_ADC);
    	joystick_tilt[i] = calculateTilt(adc_value[i]);
    }
}

void movePlayersPaddles(player *p1, player *p2){
	int joystick_tilt[2];
	calculateJoystickTilt(joystick_tilt);
	movePaddleX(p1,-joystick_tilt[0]);
	movePaddleY(p1,joystick_tilt[1]);
	convertPaddlesToChar(p1, p2);
	movePaddleX(p2,(int)bt_receive[0]-5);
	movePaddleY(p2,-((int)bt_receive[1]-5));
}
