#include <game.h>
// game run
int play(board_t board, uint8_t side, uint64_t pos) {
  if (side > 1) {
    // log this too large
    return 0;
  }

  // check if filled
  if (getpiece(board, pos) != 0) {
    // log this is filled
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

// game check win
