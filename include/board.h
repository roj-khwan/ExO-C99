#pragma once
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <bitutils.h>

typedef uint8_t boardbyte_t;
typedef uint8_t* board_t; 

#define BOARD_SIZE 3
#define BITWIDE 2
#define BOARD_T_SIZE (BOARD_SIZE * BOARD_SIZE + 3) / 4

void create(board_t* out);
int getpiece(board_t board, uint64_t pos);
int place(board_t board, uint8_t side, uint64_t pos);
int checkpattern(board_t board, uint64_t* arr, size_t length, uint8_t piece);  
void destroy(board_t out);
