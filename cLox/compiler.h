//
//  compiler.h
//  cLox
//
//  Created by Алексей Якименко on 15.07.2021.
//

#ifndef clox_compiler_h
#define clox_compiler_h

#include "object.h"
#include "vm.h"

ObjFunction* compile(const char* source);

#endif
