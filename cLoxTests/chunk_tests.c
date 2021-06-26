//
//  chunk_tests.c
//  cLoxTests
//
//  Created by Алексей Якименко on 26.06.2021.
//

#include <stdio.h>
#include <stdlib.h>
#include "unity.h"
#include "chunk.h"

void test_initChunk_setsInitialState(void) {
    
    // given
    Chunk chunk;
    
    // when
    initChunk(&chunk);
    
    // then
    TEST_ASSERT_EQUAL_INT(chunk.count, 0);
    TEST_ASSERT_EQUAL_INT(chunk.capacity, 0);
    TEST_ASSERT_EQUAL_INT(chunk.code, NULL);
    TEST_ASSERT_EQUAL_INT(chunk.lines.capacity, 0);
    TEST_ASSERT_EQUAL_INT(chunk.constants.capacity, 0);
}

void test_writeChunk_savesOperation(void) {
    
    // given
    Chunk chunk;
    initChunk(&chunk);
    
    // when
    writeChunk(&chunk, OP_RETURN, 1);
    
    // then
    TEST_ASSERT_EQUAL_INT(chunk.count, 1);
    TEST_ASSERT_EQUAL_INT(chunk.code[0], OP_RETURN);
    TEST_ASSERT_EQUAL_INT(chunk.constants.capacity, 0);
}

void test_writeChunk_writeLineArray(void) {
    
    // given
    Chunk chunk;
    initChunk(&chunk);
    
    // when
    writeChunk(&chunk, OP_RETURN, 1);
    
    // then
    TEST_ASSERT_NOT_EQUAL_INT(chunk.lines.capacity, 0);
}

void test_writeChunk_whenCapacityEqualToCount_reallocatesArray(void) {
    
    // given
    Chunk chunk;
    initChunk(&chunk);
    chunk.capacity = 12;
    chunk.count = 12;
    
    // when
    writeChunk(&chunk, OP_RETURN, 1);
    
    // then
    TEST_ASSERT_EQUAL_INT(chunk.capacity, 24);
}

void test_addConstant_returnsConstantIndex(void) {
    
    // given
    Chunk chunk;
    initChunk(&chunk);
    
    // when
    int result = addConstant(&chunk, 5);
    
    // then
    TEST_ASSERT_EQUAL_INT(result, 0);
    TEST_ASSERT_EQUAL_INT(chunk.constants.values[0], 5);
}

void test_addConstant_whenAddedFew_returnsConstantIndex(void) {
    
    // given
    Chunk chunk;
    initChunk(&chunk);
    addConstant(&chunk, 2);
    addConstant(&chunk, 4);
    
    // when
    int result = addConstant(&chunk, 5);
    
    // then
    TEST_ASSERT_EQUAL_INT(result, 2);
}

void test_addConstant_writesValueArray(void) {
    
    // given
    Chunk chunk;
    initChunk(&chunk);
    
    // when
    addConstant(&chunk, 5);
    
    // then
    TEST_ASSERT_EQUAL_INT(chunk.constants.values[0], 5);
}

void test_freeChunk_freesArray(void) {
    
    // given
    Chunk chunk;
    initChunk(&chunk);
    chunk.capacity = 12;
    chunk.count = 8;
    chunk.code = (uint8_t *)calloc(OP_RETURN, 12 * sizeof(uint8_t));
    
    // when
    freeChunk(&chunk);
    
    // then
    TEST_ASSERT_EQUAL_INT(chunk.capacity, 0);
    TEST_ASSERT_EQUAL_INT(chunk.count, 0);
    TEST_ASSERT_EQUAL_INT(chunk.code, NULL);
}

void test_freeChunk_freesValueArray(void) {
    
    // given
    Chunk chunk;
    initChunk(&chunk);
    chunk.constants.capacity = 12;
    
    // when
    freeChunk(&chunk);
    
    // then
    TEST_ASSERT_EQUAL_INT(chunk.constants.capacity, 0);
}

void run_chunk_tests(void) {
    RUN_TEST(test_initChunk_setsInitialState);
    RUN_TEST(test_writeChunk_savesOperation);
    RUN_TEST(test_writeChunk_writeLineArray);
    RUN_TEST(test_writeChunk_whenCapacityEqualToCount_reallocatesArray);
    RUN_TEST(test_addConstant_returnsConstantIndex);
    RUN_TEST(test_addConstant_whenAddedFew_returnsConstantIndex);
    RUN_TEST(test_addConstant_writesValueArray);
    RUN_TEST(test_freeChunk_freesArray);
    RUN_TEST(test_freeChunk_freesValueArray);
}
