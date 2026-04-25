#include "bitutils.h"

int setbit(byte_t* target, uint64_t bits, uint8_t value) {
    uint64_t bytes = bits / 8;
    uint8_t pad_bits = bits % 8;

    target[bytes] &= ~(1 << pad_bits); //clear the bit
    target[bytes] |= (value << pad_bits); //set the bit

    return 1;
}

int getbit(byte_t* target, uint64_t bits) {
    uint64_t bytes = bits / 8;
    uint8_t pad_bits = bits % 8;

    return (target[bytes] & (1 << pad_bits)) >> pad_bits; // isolate the bit with and then shift to the end.
}

// get
