//
//  LineTests.c
//  cLoxTests
//
//  Created by Алексей Якименко on 26.06.2021.
//

#include <stdio.h>
#include <stdlib.h>
#include "unity.h"
#include "line.h"

void test_initLineArray_setsInitialState(void) {
    
    // given
    LineArray line;
    
    // when
    initLineArray(&line);
    
    // then
    TEST_ASSERT_EQUAL_INT(line.capacity, 0);
    TEST_ASSERT_EQUAL_INT(line.count, 0);
    TEST_ASSERT_EQUAL_INT(line.lines, NULL);
}

void test_writeLine_increasesLineCounter(void) {
    
    // given
    LineArray line;
    initLineArray(&line);
    
    // when
    writeLine(&line, 13);
    
    //
    TEST_ASSERT_EQUAL_INT(line.lines[0], 13);
    TEST_ASSERT_EQUAL_INT(line.lines[1], 1);
}

void test_writeLineTwice_increasesLineCounterTwice(void) {
    
    // given
    LineArray line;
    initLineArray(&line);
    
    // when
    writeLine(&line, 13);
    writeLine(&line, 13);
    
    //
    TEST_ASSERT_EQUAL_INT(line.lines[0], 13);
    TEST_ASSERT_EQUAL_INT(line.lines[1], 2);
}

void test_writeDifferentLines_increasesLineCounters(void) {
    
    // given
    LineArray line;
    initLineArray(&line);
    
    // when
    writeLine(&line, 13);
    writeLine(&line, 14);
    
    //
    TEST_ASSERT_EQUAL_INT(line.lines[0], 13);
    TEST_ASSERT_EQUAL_INT(line.lines[1], 1);
    TEST_ASSERT_EQUAL_INT(line.lines[2], 14);
    TEST_ASSERT_EQUAL_INT(line.lines[3], 1);
}

void test_writeLine_whenCapacityLessThanCount_reallocatesArray(void) {
    
    // given
    LineArray line;
    initLineArray(&line);
    line.capacity = 8;
    line.count = 9;
    line.lines = (int *)calloc(8, 8 * sizeof(int));
    
    // when
    writeLine(&line, 13);
    
    // then
    TEST_ASSERT_EQUAL_INT(line.capacity, 16);
}

void test_writeLine_whenCapacityEqualCount_reallocatesArray(void) {
    
    // given
    LineArray line;
    initLineArray(&line);
    line.capacity = 8;
    line.count = 8;
    line.lines = (int *)calloc(8, 8 * sizeof(int));
    
    // when
    writeLine(&line, 13);
    
    // then
    TEST_ASSERT_EQUAL_INT(line.capacity, 16);
}

void test_writeLine_whenCapacityOneMoreThanCount_reallocatesArray(void) {
    
    // given
    LineArray line;
    initLineArray(&line);
    line.capacity = 8;
    line.count = 7;
    line.lines = (int *)calloc(8, 8 * sizeof(int));
    
    // when
    writeLine(&line, 13);
    
    // then
    TEST_ASSERT_EQUAL_INT(line.capacity, 16);
}

void test_writeLine_whenCapacityTwoMoreThanCount_doesNotReallocateArray(void) {
    
    // given
    LineArray line;
    initLineArray(&line);
    line.capacity = 8;
    line.count = 6;
    line.lines = (int *)calloc(8, 8 * sizeof(int));
    
    // when
    writeLine(&line, 13);
    
    // then
    TEST_ASSERT_EQUAL_INT(line.capacity, 8);
}

void test_getLine_returnsLineNumber(void) {
    
    // given
    LineArray line;
    initLineArray(&line);
    writeLine(&line, 13);
    
    // when
    int result = getLine(&line, 0);
    
    // then
    TEST_ASSERT_EQUAL_INT(result, 13);
}

void test_getLine_whenWriteFewLines_returnsLineNumber(void) {
    
    // given
    LineArray line;
    initLineArray(&line);
    writeLine(&line, 13);
    writeLine(&line, 13);
    writeLine(&line, 13);
    writeLine(&line, 13);
    writeLine(&line, 14);
    
    // when
    int result = getLine(&line, 4);
    
    // then
    TEST_ASSERT_EQUAL_INT(result, 14);
}

void run_line_tests(void) {
    RUN_TEST(test_initLineArray_setsInitialState);
    RUN_TEST(test_writeLine_increasesLineCounter);
    RUN_TEST(test_writeLineTwice_increasesLineCounterTwice);
    RUN_TEST(test_writeDifferentLines_increasesLineCounters);
    RUN_TEST(test_writeLine_whenCapacityLessThanCount_reallocatesArray);
    RUN_TEST(test_writeLine_whenCapacityEqualCount_reallocatesArray);
    RUN_TEST(test_writeLine_whenCapacityLessThanCount_reallocatesArray);
    RUN_TEST(test_writeLine_whenCapacityTwoMoreThanCount_doesNotReallocateArray);
    RUN_TEST(test_getLine_returnsLineNumber);
    RUN_TEST(test_getLine_whenWriteFewLines_returnsLineNumber);
}
