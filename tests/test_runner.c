#include "../include/test_framework.h"
#include <stdio.h>

/* Forward declarations of test functions */
int test_bitutils(void);
int test_board(void);
int test_board_stress(void);
int test_board_place(void);

int main(void) {
    printf("\n" TEST_YELLOW "╔════════════════════════════════════════╗\n");
    printf("║      ExO-C99 Unit Test Suite v1.0      ║\n");
    printf("║   Tic Tac Toe with Bit-Packed Board    ║\n");
    printf("╚════════════════════════════════════════╝" TEST_RESET "\n");
    
    /* Run all tests */
    test_bitutils();
    test_board();
    test_board_stress();
    test_board_place();
    
    TEST_SUMMARY();
}
