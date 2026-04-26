#include <stdio.h>
#include <stdint.h>
#include <game.h>
#include <bitutils.h>

int coreloop(board_t board){
    static int side = 0;
    int pos, ret = -1;
    char buf[100];

    // loop every time input was invalid
    do {
        printf("place the piece at desire position: ");
        fgets(buf, sizeof(buf), stdin);
        ret = sscanf(buf, "%d", &pos);
    } while (1 > pos || pos > 9 || ret != 1);
    
    // place piece!
    play(board, (uint8_t) side, (uint64_t) (pos - 1));
    side = 1 - side; // switch side 1 0

    // disply board
    display(board);
    
    // return state of the game
    // -1 - not finish
    // 0 - tie
    // 1 - first player win
    // 2 - second player win
    return -1;
}

int main() {
    board_t board; // this is an array of board!
    int ret = -1;

    create(&board);

    while ((ret = coreloop(board)) == -1) {
        
    }

    destroy(board);
    return 0;
}
