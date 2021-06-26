//
//  main.c
//  cLoxTests
//
//  Created by Алексей Якименко on 26.06.2021.
//

#include "unity.h"

void setUp(void) {}

void tearDown(void) {}

void run_line_tests(void);
void run_chunk_tests(void);
void run_value_tests(void);

int main(int argc, const char * argv[]) {
    UNITY_BEGIN();
    run_line_tests();
    run_chunk_tests();
    run_value_tests();
    return UNITY_END();
}
