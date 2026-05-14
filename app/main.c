#include "stdio.h"
#include "game.h"

int requestmove() {
    int pos, ret = -1;
    char* getret;
    char buf[100];

    // loop every time input was invalid
    do {
        printf("place the piece at desire position: ");
		getret = fgets(buf, sizeof(buf), stdin);
        ret = sscanf(buf, "%d", &pos);
    } while (1 > pos || pos > 9 || ret != 1 || getret == NULL);
    
  return pos;
}
int coreloop(board_t board){
    static int side = 0, turn = 0;
    int pos, ret = -1;

    pos = requestmove();
    
    if (!play(board, (uint8_t) side, (uint64_t) (pos - 1))) {
		printf("Can't place on position %d\n", pos + 1);
        return -1;
    }

    display(board);

    if (checkwin(board, side + 1)) 
        return side + 1;
    else if (++turn >= 9)
        return 0;
    
    side = 1 - side; // switch side 1 0
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
