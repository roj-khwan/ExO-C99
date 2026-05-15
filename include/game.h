#include <stdio.h>
#include "board.h"

int8_t checkfull(board_t board);
int8_t checkwin(board_t board, uint8_t piece);
int8_t play(board_t board, uint8_t side, int16_t pos);
void display(board_t board); 
