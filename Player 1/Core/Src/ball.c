#include "ball.h"
#include "display.h"

#ifndef MATH_H_
#define MATH_H_
#include "math.h"
#endif

#ifndef STDLIB_H_
#define STDLIB_H_
#include <stdlib.h>
#endif


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
