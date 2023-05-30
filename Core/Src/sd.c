#include "fatfs.h"


FATFS FatFs; 	//Fatfs handle
FIL fil; 		//File handle
FRESULT fres; //Result after operations

int SD_Init(){
	int err = 0;
	fres = f_mount(&FatFs, "", 1);
	if (fres != FR_OK) err = 1;
	return err;
}

int SD_saveScore(int score){
	int err = 0;
	char c_score[4];

	fres = f_open(&fil, "score.txt", FA_WRITE | FA_OPEN_ALWAYS | FA_CREATE_ALWAYS);
	if(fres != FR_OK) err = 1;

	itoa(score, c_score, 10);

	UINT bytesWrote;
    fres = f_write(&fil, c_score, 4, &bytesWrote);
    if(fres != FR_OK) err = 2;

    f_close(&fil);
    //f_mount(NULL, "", 0);
    return err;
}

