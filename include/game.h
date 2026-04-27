#include <stdio.h>
#include "board.h"

int checkfull(board_t board);
int checkwin(board_t board, uint8_t piece);
int play(board_t board, uint8_t side, uint64_t pos);
int display(board_t board); 
