#include "bluetooth.h"

unsigned char bt_data[7] = {0,0,0,0,0,0,200};
unsigned char bt_receive[2];

void startBluetooth(){
	HAL_UART_Transmit_DMA(&BLUETOOTH, bt_data, sizeof(bt_data));
	HAL_UART_Receive_DMA(&BLUETOOTH, bt_receive, sizeof(bt_receive));
}

void stopBluetooth(){
	HAL_UART_DMAStop(&BLUETOOTH);
}

void convertPaddlesToChar(player *p1, player *p2){
	bt_data[0] = (unsigned char)p1->x;
	bt_data[1] = (unsigned char)p1->y;
	bt_data[2] = (unsigned char)p2->x;
	bt_data[3] = (unsigned char)p2->y;
}

void convertBallToChar(ball *b){
	bt_data[4] = (unsigned char)b->x;
	bt_data[5] = (unsigned char)b->y;
}
