#pragma once
#include <stdint.h>

typedef uint8_t byte_t;

int setbit(byte_t* target, uint64_t bit, uint8_t value);
int getbit(byte_t* target, uint64_t bit);