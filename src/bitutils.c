#include "bitutils.h"

int setbit(byte_t* target, uint64_t bits, uint8_t value) {
    uint8_t bytes = bits / 8;
    uint8_t pad_bits = bits % 8;

    target[bytes] &= ~(1 << pad_bits); //clear the bit
    target[bytes] |= (value << pad_bits); //clear the bit

    return 1;
}