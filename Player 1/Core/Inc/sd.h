#define SD_SPI_HANDLE hspi2

int SD_Init();
int SD_saveScore(int score);
int SD_readScore(char *c_score);
