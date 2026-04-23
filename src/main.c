#include <stdio.h>
#include <stdint.h>
#include <board.h>
#include <bitutils.h>

int main() {
    board_t board; // this is an array of board!

    create(&board);

    printf("%b\n", *board);

    setbit(board, 3, 1);
    setbit(board, 4, 1);

    printf("%.b\n", *board);

    destroy(board);
    return 0;
}