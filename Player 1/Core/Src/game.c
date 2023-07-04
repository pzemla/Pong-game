#include "game.h"
#include "display.h"
#include "sd.h"

#include <math.h>
#include <stdlib.h>

uint8_t score[2] = {0,0};
char c_score[4] ="0000";

void doGameTick(ball *b, player *p1, player *p2)
{
	wallBounce(b);
	paddleBounce(b, p1, p2);
	updateBall(b);
	convertBallToChar(b);
}

void restartGame(ball *b, player *p1, player *p2)
{
	stopGameTicks();
	HAL_TIM_Base_Stop_IT(&GAME_TIMER);
	clearDisplay();
	resetGameData(b, p1, p2);
	convertPaddlesToChar(p1, p2);
	convertBallToChar(b);
	drawNewGame();
	//for(int i =0; i<100000; i++);
	startBluetooth();
	startGameTicks();
	HAL_TIM_Base_Start_IT(&GAME_TIMER);
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
	//stopBluetooth();
	if(b->y > 160) score[0]++;
	if(b->y < 0) score[1]++;
	stopGameTicks();
	drawGameOver(score);
	if(checkHighScore()) saveNewScore();
}

void saveNewScore(){
	int score_temp = 0;
	score_temp = score[0]*100 + score[1];
	SD_saveScore(score_temp);
}

int checkHighScore(){
	char c_score_temp[2];
	int score1, score2;
	SD_readScore(c_score);
	c_score_temp[0] = c_score[0];
	c_score_temp[1] = c_score[1];
	score1 = atoi(c_score_temp);
	c_score_temp[0] = c_score[2];
	c_score_temp[1] = c_score[3];
	score2 = atoi(c_score_temp);
	if(abs(score1-score2) > abs(score[0]-score[1])) return 0;
	else return 1;
}

void startGameTicks()
{
	HAL_TIM_Base_Start_IT(&PADDLE_TIMER);
}

void stopGameTicks()
{
	HAL_TIM_Base_Stop_IT(&PADDLE_TIMER);
}

void checkGameOver(ball *b, int *flag){
	if((b->y>160 || b->y<0)){
				gameOver(b);
				*flag=1;
			 }
}

void checkRestartGame(ball *b, player *p1, player *p2, int *flag){
	if(HAL_GPIO_ReadPin(BTN_GPIO_Port, BTN_Pin) == GPIO_PIN_RESET){
		*flag=0;
		restartGame(b, p1, p2);
	}
}
