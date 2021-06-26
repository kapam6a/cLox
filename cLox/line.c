//
//  line.c
//  cLox
//
//  Created by Алексей Якименко on 25.06.2021.
//

#include "line.h"
#include "memory.h"

void initLineArray(LineArray* array) {
    array->capacity = 0;
    array->lines = NULL;
}

void writeLine(LineArray* array, int line) {
    if (array->capacity < line) {
        int oldCapacity = array->capacity;
        array->capacity = GROW_CAPACITY(line);
        array->lines = GROW_ARRAY(int, array->lines, line, array->capacity);
        for (int i = oldCapacity; i < array->capacity; i++) {
            array->lines[i] = 0;
        }
    }
    array->lines[line]++;
}

int getLine(LineArray* array, int offset) {
    int opNumber = 0;
    for (int i = 0; i < array->capacity; i++) {
        opNumber += array->lines[i];
        if (offset < opNumber) {
            return i;
        }
    }
    return array->capacity;
}
