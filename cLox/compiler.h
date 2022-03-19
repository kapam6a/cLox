//
//  compiler.h
//  cLox
//
//  Created by Алексей Якименко on 15.07.2021.
//

#ifndef clox_compiler_h
#define clox_compiler_h

#include "vm.h"

bool compile(const char* source, Chunk* chunk);

#endif
