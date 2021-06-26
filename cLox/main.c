//
//  main.c
//  cLox
//
//  Created by Алексей Якименко on 24.06.2021.
//

#include <stdio.h>
#include "chunk.h"
#include "debug.h"
#include "check.h"

int main(int argc, const char * argv[]) {
    Chunk chunk;
    initChunk(&chunk);
    int constant = addConstant(&chunk, 1.2);
    writeChunk(&chunk, OP_CONSTANT, 12);
    writeChunk(&chunk, constant, 12);
    writeChunk(&chunk, OP_RETURN, 12);
    disassembleChunk(&chunk, "test chunk");
    freeChunk(&chunk);
    return 0;
}
