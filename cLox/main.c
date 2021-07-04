//
//  main.c
//  cLox
//
//  Created by Алексей Якименко on 24.06.2021.
//

#include <stdio.h>
#include "chunk.h"
#include "debug.h"
#include "vm.h"

int main(int argc, const char * argv[]) {
    initVM();
    Chunk chunk;
    initChunk(&chunk);
    
    int constant = addConstant(&chunk, 1.2);
    writeChunk(&chunk, OP_CONSTANT, 12);
    writeChunk(&chunk, constant, 12);
    
    constant = addConstant(&chunk, 3.4);
    writeChunk(&chunk, OP_CONSTANT, 123);
    writeChunk(&chunk, constant, 123);
    
    writeChunk(&chunk, OP_ADD, 123);
    
    constant = addConstant(&chunk, 5.6);
    writeChunk(&chunk, OP_CONSTANT, 123);
    writeChunk(&chunk, constant, 123);
    
    writeChunk(&chunk, OP_DIVIDE, 123);
    
    writeChunk(&chunk, OP_NEGATE, 12);
    writeChunk(&chunk, OP_RETURN, 12);
    
    disassembleChunk(&chunk, "test chunk");
    
    interpret(&chunk);
    
    freeVM();
    freeChunk(&chunk);
    
    return 0;
}
