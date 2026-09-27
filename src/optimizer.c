#include "include/optimizer.h"
#include <stdlib.h>
#include <stdio.h>

instrVector instrVector_init() {
    instrVector vec;
    vec.instr = NULL;
    vec.size = 0;
    vec.count = 0;
    return vec;
}

void instrVector_free(instrVector *vec) {
    free(vec->instr);
    vec->instr = NULL;
}

void instrVector_push(instrVector *vec, instr_t instr) {
    if (vec->count == vec->size) {
        size_t size = vec->size < 8 ? 8 : vec->size*2;
        void *temp = realloc(vec->instr, size * sizeof(instr_t));
        if (!temp) {
            fprintf(stderr, "[FATAL] Out of memory\n");
            instrVector_free(vec);
            exit(1);
        }
        vec->instr = temp;
        vec->size = size;
    }
    vec->instr[vec->count] = instr;
}

instrVector optimize(int level, const vector *v, const indexSet *set) {
    instrVector vec = instrVector_init();
    instr_t instr;

    if (level == 0) {
        // Skips optimization
        size_t len = v->count;
        for (size_t i = 0; i < len; i++) {
            switch (v->tokens[i].type) {
                case INCREMENT:
                    instr.type = IR_ADD;
                    instr.operand = 1;
                    instrVector_push(&vec, instr);
                    break;
                case DECREMENT:
                    instr.type = IR_ADD;
                    instr.operand = -1;
                    instrVector_push(&vec, instr);
                    break;
                case LEFT:
                    instr.type = IR_MOVE;
                    instr.operand = -1;
                    instrVector_push(&vec, instr);
                    break;
                case RIGHT:
                    instr.type = IR_MOVE;
                    instr.operand = 1;
                    instrVector_push(&vec, instr);
                    break;
                case OUT:
                    instr.type = IR_OUT;
                    instr.operand = 0;
                    instrVector_push(&vec, instr);
                    break;
                case IN:
                    instr.type = IR_IN;
                    instr.operand = 0;
                    instrVector_push(&vec, instr);
                    break;
                case START:
                    instr.type = IR_START;
                    instr.operand = 0;
                    instrVector_push(&vec, instr);
                    break;
                case END:
                    instr.type = IR_END;
                    instr.operand = 0;
                    instrVector_push(&vec, instr);
                    break;
                case EOF_TOKEN:
                    instr.type = IR_EOF;
                    instr.operand = 0;
                    instrVector_push(&vec, instr);
                    break;
                default:
                    break;
            }
        }
        return vec;
    }
    else if (level == 1) {
        return vec;
    }
    else if (level == 2) {
        return vec;
    }
    else if (level == 3) {
        return vec;
    }
    return vec;
}