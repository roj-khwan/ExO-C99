#include "board.h"

void create(board_t* board) {
    // create a board_t * board_size for the board
    // the board was dynamic, as in it was preprocessingly calculate how much byte it need.
    // It allocate memory first the 
    *board = (board_t) calloc(BOARD_T_SIZE, sizeof(boardbyte_t));
}

int place(board_t board, uint8_t side, uint8_t pos) {
    // Check
    
    // edit cell in board
    // 1 cell contain of 2 bit, Xx
    // X - side
    // x - filled or not
    setbit(board, pos * BITWIDE, 1);
    setbit(board, pos * BITWIDE + 1, side);

    return 0;
}
// fetching

void destroy(board_t board) {
    free(board);
}
