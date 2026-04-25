#include "../include/test_framework.h"
#include "../include/board.h"
#include <stdlib.h>

int test_board() {
    TEST_SUITE("Board Management");
    
    board_t board;
    
    /* Test board creation */
    create(&board);
    ASSERT_NOT_NULL(board, "board should be allocated after create");
    
    /* Test board size calculation */
    /* BOARD_SIZE = 3, BOARD_T_SIZE = (3*3+3)/4 = 12/4 = 3 bytes */
    uint8_t expected_size = BOARD_T_SIZE;
    printf("  Board size: %d bytes (for 3x3 = 9 cells, 2 bits per cell)\n", expected_size);
    ASSERT_EQUAL(expected_size, 3, "board should be 3 bytes for 3x3 board");
    
    /* Test board initialization (should be zero-filled) */
    for (int i = 0; i < BOARD_T_SIZE; i++) {
        ASSERT_EQUAL(board[i], 0, "board bytes should be initialized to 0");
    }
    
    /* Test destroy */
    destroy(board);
    ASSERT_EQUAL(board == NULL, 0, "board pointer should exist (manual memory management)");
    
    return 0;
}

int test_board_stress() {
    TEST_SUITE("Board Stress Tests");
    
    /* Stress test: create and destroy multiple boards */
    for (int i = 0; i < 100; i++) {
        board_t temp;
        create(&temp);
        ASSERT_NOT_NULL(temp, "stress test board creation");
        destroy(temp);
    }
    
    return 0;
}

int test_board_place() {
    TEST_SUITE("Board Place Tests");
    

    int i;
    board_t board;
    create(&board);
    
    place(board, 1, 0);
    ASSERT_EQUAL(board[0], 0b11, "board first byte should equal to 0b11");
    
    place(board, 0, 3);
    ASSERT_EQUAL(board[0], 0b01000011, "board first byte should equal to 0b1000011");
    
    place(board, 1, 5);
    ASSERT_EQUAL(board[1], 0b1100, "board second byte should equal to 0b1100");

    return 0;
}

