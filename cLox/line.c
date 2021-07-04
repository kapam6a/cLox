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
    array->count = 0;
    array->lines = NULL;
}

void writeLine(LineArray* array, int line) {
    if (array->capacity < array->count + 2) {
        int oldCapacity = array->capacity;
        array->capacity = GROW_CAPACITY(oldCapacity);
        array->lines = GROW_ARRAY(int, array->lines, oldCapacity, array->capacity);
    }
    int previousIndex = array->count - 2;
    if (previousIndex >= 0 && array->lines[previousIndex] == line) {
        array->lines[previousIndex + 1]++;
    } else {
        array->lines[array->count] = line;
        array->lines[array->count + 1] = 1;
        array->count = array->count + 2;
    }
}

int getLine(LineArray* array, int offset) {
    int opNumber = 0;
    for (int i = 1; i < array->capacity; i = i + 2) {
        opNumber += array->lines[i];
        if (offset < opNumber) {
            return array->lines[i - 1];
        }
    }
    return 0;
}
