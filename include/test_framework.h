#pragma once
#include <stdio.h>
#include <stdint.h>
#include <string.h>

/* Simple unit testing framework for C */

typedef struct {
    int passed;
    int failed;
    int skipped;
} TestStats;

extern TestStats test_stats;

/* Color codes for terminal output */
#define TEST_GREEN "\x1b[32m"
#define TEST_RED "\x1b[31m"
#define TEST_YELLOW "\x1b[33m"
#define TEST_RESET "\x1b[0m"

/* Test macros */
#define ASSERT_EQUAL(actual, expected, msg) \
    do { \
        if ((actual) != (expected)) { \
            printf(TEST_RED "✗ FAIL" TEST_RESET ": %s\n", msg); \
            printf("  Expected: %d, Got: %d\n", (int)(expected), (int)(actual)); \
            test_stats.failed++; \
        } else { \
            printf(TEST_GREEN "✓ PASS" TEST_RESET ": %s\n", msg); \
            test_stats.passed++; \
        } \
    } while (0)

#define ASSERT_NOT_NULL(ptr, msg) \
    do { \
        if ((ptr) == NULL) { \
            printf(TEST_RED "✗ FAIL" TEST_RESET ": %s (pointer is NULL)\n", msg); \
            test_stats.failed++; \
        } else { \
            printf(TEST_GREEN "✓ PASS" TEST_RESET ": %s\n", msg); \
            test_stats.passed++; \
        } \
    } while (0)

#define ASSERT_NULL(ptr, msg) \
    do { \
        if ((ptr) != NULL) { \
            printf(TEST_RED "✗ FAIL" TEST_RESET ": %s (pointer is not NULL)\n", msg); \
            test_stats.failed++; \
        } else { \
            printf(TEST_GREEN "✓ PASS" TEST_RESET ": %s\n", msg); \
            test_stats.passed++; \
        } \
    } while (0)

#define TEST_SUITE(name) \
    printf("\n" TEST_YELLOW "=== Test Suite: %s ===" TEST_RESET "\n", name)

#define TEST_SKIP(msg) \
    do { \
        printf(TEST_YELLOW "⚠ SKIP" TEST_RESET ": %s\n", msg); \
        test_stats.skipped++; \
    } while (0)

#define TEST_SUMMARY() \
    do { \
        printf("\n" TEST_YELLOW "=== Test Summary ===" TEST_RESET "\n"); \
        printf(TEST_GREEN "Passed:  %d\n" TEST_RESET, test_stats.passed); \
        printf(TEST_RED "Failed:  %d\n" TEST_RESET, test_stats.failed); \
        printf(TEST_YELLOW "Skipped: %d\n" TEST_RESET, test_stats.skipped); \
        printf(TEST_YELLOW "Total:   %d\n" TEST_RESET, test_stats.passed + test_stats.failed + test_stats.skipped); \
        return (test_stats.failed == 0) ? 0 : 1; \
    } while (0)
