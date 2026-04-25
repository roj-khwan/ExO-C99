# Unit Test Suite Documentation

## Overview
This project includes a comprehensive unit testing suite for the ExO-C99 Tic Tac Toe game. The tests verify the correctness of bit manipulation utilities and board management functions without modifying any original source code.

## Test Files

### Core Files (No Original Files Modified)

#### `tests/test_framework.h` & `tests/test_framework.c`
Custom unit testing framework providing:
- Simple assertion macros (`ASSERT_EQUAL`, `ASSERT_NOT_NULL`, `ASSERT_NULL`)
- Color-coded test output (green for pass, red for fail, yellow for info)
- Test statistics tracking

#### `tests/test_bitutils.c`
Tests for bit manipulation functions (`setbit`, `getbit`):
- Setting and getting individual bits
- Multiple bits in same/different bytes
- Bit clearing
- Boundary conditions (bit 0, bit 7, bit 15)
- Byte-level patterns (all 8 bits set)

**Test Count:** 10 assertions

#### `tests/test_board.c`
Tests for board management functions:
- Board creation and destruction
- Board size calculations (3 bytes for 3×3 board)
- Board initialization (zero-filled)
- Stress tests (100 create/destroy cycles)

**Test Count:** 106 assertions (6 base + 100 stress tests)

#### `tests/test_runner.c`
Main test driver that:
- Runs all test suites
- Displays formatted test summary
- Returns appropriate exit code (0 = all pass, 1 = failures)

## Building and Running Tests

### Run tests:
```bash
make test
```

### Build everything:
```bash
make all        # Build main program
make test       # Run tests
make clean      # Clean build artifacts
```

## Test Statistics

- **Total Tests:** 116 assertions across 3 test suites
- **Pass Rate:** 100% (all original functionality working)
- **Build Warnings:** Original code warnings preserved (not modified)

## Usage in Future Tests

To add more tests:

1. Create new file: `tests/test_myfeature.c`
2. Include framework: `#include "../include/test_framework.h"`
3. Define test function: `int test_myfeature(void)`
4. Use macros: `ASSERT_EQUAL()`, `ASSERT_NOT_NULL()`, etc.
5. Call from `test_runner.c`: `test_myfeature();`

Example:
```c
int test_myfeature() {
    TEST_SUITE("My Feature");
    
    // Your test code here
    ASSERT_EQUAL(2 + 2, 4, "addition works");
    
    return 0;
}
```

## Original Files - Untouched

The following files remain in their original state:
- `src/main.c`
- `src/board.c`
- `src/game.c`
- `src/bitutils.c`
- `include/board.h`
- `include/game.h`
- `include/bitutils.h`

Only `Makefile` was updated to include test build targets.
