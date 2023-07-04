#ifndef __BALL_H__
#define __BALL_H__
#endif

#ifndef DEFINITIONS_H_
#define DEFINITIONS_H_
#include "definitions.h"
#endif


void updateBall(ball *b);
void calculateBallPosition(ball *b);
void wallBounce(ball *b);
void paddleBounce(ball *b, player *p1, player *p2);
void calculatePaddleBounce(ball *b, player* p, int direction);
