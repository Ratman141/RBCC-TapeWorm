#ifndef TAPEWORM_CODEGEN_H
#define TAPEWORM_CODEGEN_H
#include "optimizer.h"

typedef enum {
    OP_HALT = 0x00,
    OP_ADD = 0x01,
    OP_MOVE = 0x02,
    OP_IN = 0x03,
    OP_OUT = 0x04,
    OP_START = 0x05,
    OP_END = 0x06,
    OP_SET_ZERO = 0x07,
}opcode;

void transpile(instrVector *vec, char* output);

#endif //TAPEWORM_CODEGEN_H
