#include "board.h"

void create(board_t* board) {
    // create a board_t * board_size for the board
    // the board was dynamic, as in it was preprocessingly calculate how much byte it need.
    // It allocate memory first the 
    *board = (board_t) calloc(BOARD_T_SIZE, sizeof(boardbyte_t));
}

int getpiece(board_t board, uint64_t pos) {
    if (pos >= BOARD_SIZE * BOARD_SIZE) {
        // TODO : Loging
        return -1;
    }

    int filled, piece;
    filled = getbit(board, pos * BITWIDE);
    piece = getbit(board, pos * BITWIDE + 1);
    
    return filled + (piece & filled);
}

int place(board_t board, uint8_t side, uint64_t pos) {
    if (pos >= BOARD_SIZE * BOARD_SIZE) {
        // TODO : Loging
        return -1;
    }
    // edit cell in board
    // 1 cell contain of 2 bit, mn
    // m - side
    // n - filled or not
    setbit(board, pos * BITWIDE, 1);
    setbit(board, pos * BITWIDE + 1, side);

    return 0;
}

int checkpattern(board_t board, uint64_t* arr, size_t length, uint8_t piece) {
    for (size_t i = 0; i < length; i++){
        if (BOARD_SIZE * BOARD_SIZE <= arr[i])
            return 0;

        if (piece != getpiece(board, arr[i]))
            return 0;
    }
    return 1; 
}

void destroy(board_t board) {
    free(board);
}

int copy(board_t dest, board_t src) {
    for (size_t i = 0; i < BOARD_T_SIZE; i++) {
        dest[i] = src[i];
    }
}
