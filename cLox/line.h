//
//  line.h
//  cLox
//
//  Created by Алексей Якименко on 25.06.2021.
//

#ifndef clox_line_h
#define clox_line_h

#include "common.h"

typedef struct {
    int capacity;
    int* lines;
} LineArray;

void initLineArray(LineArray* array);
void writeLine(LineArray* array, int line);
int getLine(LineArray* array, int offset);

#endif
