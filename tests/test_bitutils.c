#include "../include/test_framework.h"
#include "../include/bitutils.h"
#include <stdlib.h>

int test_bitutils() {
    TEST_SUITE("Bit Utilities");
    
    int i;
    uint8_t buffer[10] = {0};
    
    /* Test setbit and getbit basic functionality */
    ASSERT_EQUAL(setbit(buffer, 0, 1), 1, "setbit should return 1");
    ASSERT_EQUAL(getbit(buffer, 0), 1, "getbit should return 1 after setting bit 0");
    
    ASSERT_EQUAL(getbit(buffer, 1), 0, "getbit should return 0 for unset bit 1");
    
    /* Test setting multiple bits in same byte */
    setbit(buffer, 3, 1);
    ASSERT_EQUAL(getbit(buffer, 3), 1, "getbit should return 1 after setting bit 3");
    
    /* Test bits in different bytes */
    setbit(buffer, 8, 1);  /* First bit of second byte */
    ASSERT_EQUAL(getbit(buffer, 8), 1, "getbit should return 1 after setting bit 8");
    
    /* Test clearing bits */
    setbit(buffer, 0, 0);
    ASSERT_EQUAL(getbit(buffer, 0), 0, "getbit should return 0 after clearing bit 0");
    
    /* Test boundary bits */
    setbit(buffer, 7, 1);  /* Last bit of first byte */
    ASSERT_EQUAL(getbit(buffer, 7), 1, "getbit should return 1 for bit 7");
    
    setbit(buffer, 15, 1); /* Last bit of second byte */
    ASSERT_EQUAL(getbit(buffer, 15), 1, "getbit should return 1 for bit 15");
    
    /* Test value 0 explicitly */
    setbit(buffer, 20, 0);
    ASSERT_EQUAL(getbit(buffer, 20), 0, "getbit should return 0 for explicitly set 0");
    
    /* Test all bits in a byte pattern */
    uint8_t test_byte[2] = {0};
    for (i = 0; i < 16; i++) {
        setbit(test_byte, i, 1);
    }
    ASSERT_EQUAL(test_byte[0], 0xFF, "0 - 7 bits set should equal 0xFF");
    ASSERT_EQUAL(test_byte[1], 0xFF, "8 - 15 bits set should equal 0xFF");

    /* Test specifix bit pattern */
    uint8_t test_2_byte[2] = {0};
    for (i = 0; i < 16; i += 2) {
        setbit(test_2_byte, i, 1);
    }
    ASSERT_EQUAL(test_2_byte[0], 0b1010101, "0 - 7 bits set should equal 0b1010101");
    ASSERT_EQUAL(test_2_byte[1], 0b1010101, "8 - 15 bits set should equal 0b1010101");

    
    return 0;
}
