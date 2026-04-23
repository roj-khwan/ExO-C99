#pragma once
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef uint8_t boardbyte_t;
typedef uint8_t* board_t; 

#define BOARD_SIZE 3
#define BOARD_T_SIZE (BOARD_SIZE * BOARD_SIZE + 3) / 4

void create(board_t* out);
void destroy(board_t out);