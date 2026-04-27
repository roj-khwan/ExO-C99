#include "game.h"
// game run
int play(board_t board, uint8_t side, uint64_t pos) {
  if (side > 1) {
    printf("Side is binary!");
    return 0;
  }

  // check if filled
  if (getpiece(board, pos) != 0) {
    // log this is filled
    printf("It's filled!");
    return 0;
  }
  
  place(board, side, pos);
  return 1;
}

int display(board_t board) {
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

  return 0;
}

int checkfull(board_t board) {
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

int checkwin(board_t board, uint8_t piece) {
  size_t i, j;
  uint8_t win = 0;
  uint64_t harr[BOARD_SIZE];
  uint64_t varr[BOARD_SIZE];

  for (i = 0; i < BOARD_SIZE; i++) {
    for (j = 0; j < BOARD_SIZE; j++) {
      harr[j] = i * BOARD_SIZE + j;
      varr[j] = i + j * BOARD_SIZE;
    }
    // check vertical
    win |= checkpattern(board, varr, BOARD_SIZE, piece);
    // check horizontal
    win |= checkpattern(board, harr, BOARD_SIZE, piece);
  }

  for (i = 0; i < BOARD_SIZE; i++) {
    harr[i] = i * BOARD_SIZE + i;
    varr[i] = i * BOARD_SIZE + BOARD_SIZE - 1 - i;
  }
  // check forward diagonal
  win |= checkpattern(board, varr, BOARD_SIZE, piece);
  // check backward diagonal
  win |= checkpattern(board, harr, BOARD_SIZE, piece);
  
  return win;
}
