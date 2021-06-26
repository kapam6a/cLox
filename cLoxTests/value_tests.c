//
//  value_tests.c
//  cLoxTests
//
//  Created by Алексей Якименко on 26.06.2021.
//

#include <stdio.h>
#include <stdlib.h>
#include "unity.h"
#include "value.h"

void test_initValueArray_setsInitialState(void) {
    
    // given
    ValueArray value;
    
    // when
    initValueArray(&value);
    
    // then
    TEST_ASSERT_EQUAL_INT(value.count, 0);
    TEST_ASSERT_EQUAL_INT(value.capacity, 0);
    TEST_ASSERT_EQUAL_INT(value.values, NULL);
}

void test_writeValueArray_savesValue(void) {
    
    // given
    ValueArray value;
    initValueArray(&value);
    
    // when
    writeValueArray(&value, 5);
    
    // then
    TEST_ASSERT_EQUAL_INT(value.count, 1);
    TEST_ASSERT_EQUAL_INT(value.values[0], 5);
}

void test_writeValueArray_whenCapacityEqualToCount_reallocatesArray(void) {
    
    // given
    ValueArray value;
    initValueArray(&value);
    value.capacity = 12;
    value.count = 12;
    
    // when
    writeValueArray(&value, 5);
    
    // then
    TEST_ASSERT_EQUAL_INT(value.capacity, 24);
}

void test_freeValueArray_freesArray(void) {
    
    // given
    ValueArray value;
    value.capacity = 12;
    value.count = 8;
    value.values = (Value *)calloc(4, 12 * sizeof(Value));
    
    // when
    freeValueArray(&value);
    
    // then
    TEST_ASSERT_EQUAL_INT(value.capacity, 0);
    TEST_ASSERT_EQUAL_INT(value.count, 0);
    TEST_ASSERT_EQUAL_INT(value.values, NULL);
}

void run_value_tests(void) {
    RUN_TEST(test_initValueArray_setsInitialState);
    RUN_TEST(test_writeValueArray_savesValue);
    RUN_TEST(test_writeValueArray_whenCapacityEqualToCount_reallocatesArray);
    RUN_TEST(test_freeValueArray_freesArray);
}
