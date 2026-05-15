#include "game.h"
#include <stdbool.h>

// game run
// TODO : no output make the out put on main side only
int8_t play(board_t board, uint8_t side, int16_t pos) {
  if (side > 1) {
    return 0;
  }

  // check if filled
  if (getpiece(board, (uint64_t) pos) != 0) {
    // log this is filled
    return 0;
  }
  
  place(board, side, (uint64_t) pos);
  return 1;
}

void display(board_t board) {
  size_t x, y;

  for (y = BOARD_SIZE; y-- > 0;){
    for (x = 0; x < BOARD_SIZE; x++){
      int bitpos = y * BOARD_SIZE + x;
      int piece = getpiece(board, bitpos);
      
      putchar(piece ? ((piece - 1) ? 'X' : 'O') : '_');

      (x < BOARD_SIZE - 1) ? putchar('|') : 0;
    }
    putchar('\n');
  }
}

int8_t checkfull(board_t board) {
  size_t x, y;

  for (y = 0; y < BOARD_SIZE; y++){
    for (x = 0; x < BOARD_SIZE; x++){
      int bitpos = y * BOARD_SIZE + x;
      int piece = getpiece(board, bitpos);
      
      if (piece == 0) 
        return 0;
    }
  }
  return 1;
}

void build_winpattern(uint64_t (*arr)[BOARD_SIZE]) {
  size_t i, j;
  
  for (i = 0; i < BOARD_SIZE; i++) {
    for (j = 0; j < BOARD_SIZE; j++) {
      arr[i][j] = i + j * BOARD_SIZE; // verticals
      arr[i + BOARD_SIZE][j] = i * BOARD_SIZE + j; // horizontals
    }
  }

  for (i = 0; i < BOARD_SIZE; i++) {
    arr[2 * BOARD_SIZE][i] = i * BOARD_SIZE + i;
    arr[2 * BOARD_SIZE + 1][i] = i * BOARD_SIZE + BOARD_SIZE - 1 - i;
  }
}

int8_t checkwin(board_t board, uint8_t piece) {
  #define PATTERN_SIZE BOARD_SIZE * 2 + 2
  // horizontals + verticals + 2 diagonals
  static uint64_t winpattern[PATTERN_SIZE][BOARD_SIZE];
  static char patternbuilt = false; 

  if (!patternbuilt) {
    build_winpattern(winpattern);
    patternbuilt = true;
  }
  for (size_t i = 0; i < BOARD_SIZE * 2 + 2; i++) {
    if (checkpattern(board, winpattern[i], BOARD_SIZE, piece))
      return true;
  }
  
  return false;
}
