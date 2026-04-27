#include "stdio.h"
#include "game.h"

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
    ret = play(board, (uint8_t) side, (uint64_t) (pos - 1));
    // check can't play
    if (!ret)
        return -1;
    
    side = 1 - side; // switch side 1 0

    // disply board
    display(board);

    // return state of the game
    // -1 - not finish
    // 0 - tie
    // 1 - first player win
    // 2 - second player win
    if (checkwin(board, 1)) 
        return 1;
    else if (checkwin(board, 2))
        return 2;
    else if (checkfull(board))
        return 0;
    
    return -1;
}

int main() {
    board_t board; // this is an array of board!
    int ret = -1;

    create(&board);

    display(board);
    while ((ret = coreloop(board)) == -1) {} 

    if (ret)
        printf("Player %d Win!!!\n", ret);
    else
        printf("TIE!!!\n");

    destroy(board);
    return 0;
}
