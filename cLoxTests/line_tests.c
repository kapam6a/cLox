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
    TEST_ASSERT_EQUAL_INT(line.lines, NULL);
}

void test_writeLine_increasesLineCounter(void) {
    
    // given
    LineArray line;
    initLineArray(&line);
    
    // when
    writeLine(&line, 13);
    
    //
    TEST_ASSERT_EQUAL_INT(line.lines[13], 1);
}

void test_writeLine_whenCapacityLessThanLine_reallocatesArray(void) {
    
    // given
    LineArray line;
    line.capacity = 12;
    line.lines = (int *)calloc(12, 12 * sizeof(int));
    
    // when
    writeLine(&line, 13);
    
    // then
    TEST_ASSERT_EQUAL_INT(line.capacity, 26);
    TEST_ASSERT_EQUAL_INT(line.lines[25], 0);
}

void test_writeLine_whenCapacityMoreThanLine_doesNotReallocateArray(void) {
    
    // given
    LineArray line;
    line.capacity = 14;
    line.lines = (int *)calloc(14, 14 * sizeof(int));
    
    // when
    writeLine(&line, 13);
    
    // then
    TEST_ASSERT_EQUAL_INT(line.capacity, 14);
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

void run_line_tests(void) {
    RUN_TEST(test_initLineArray_setsInitialState);
    RUN_TEST(test_writeLine_increasesLineCounter);
    RUN_TEST(test_writeLine_whenCapacityLessThanLine_reallocatesArray);
    RUN_TEST(test_writeLine_whenCapacityMoreThanLine_doesNotReallocateArray);
    RUN_TEST(test_getLine_returnsLineNumber);
}
