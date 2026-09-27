#ifndef TAPEWORM_OPTIMIZER_H
#define TAPEWORM_OPTIMIZER_H
#include "lexer.h"
#include "parser.h"

typedef enum {
    IR_ADD,
    IR_MOVE,
    IR_OUT,
    IR_IN,
    IR_START,
    IR_END,
    IR_EOF,
    SET_ZERO
} IRType;

typedef struct {
    IRType type;
    size_t operand;
} instr_t;

typedef struct {
    instr_t *instr;
    size_t size;
    size_t count;
} instrVector;

instrVector instrVector_init();

void instrVector_free(instrVector *vec);

void instrVector_push(instrVector *vec, instr_t instr);

instrVector optimize(int level, const vector *v, const indexSet *set);

#endif //TAPEWORM_OPTIMIZER_H
