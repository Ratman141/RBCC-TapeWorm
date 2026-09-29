#ifndef TAPEWORM_INTERPRETER_H
#define TAPEWORM_INTERPRETER_H
#include "parser.h"
#include "optimizer.h"

void interpret(const instrVector *vec, indexSet *set, unsigned char *tape, int *index);

void run_repl();

#endif //TAPEWORM_INTERPRETER_H
