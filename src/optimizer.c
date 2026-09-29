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
    int count = 0;

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
    if (level >= 1) {
        size_t len = v->count;
        for (size_t i = 0; i < len; i++) {
            switch (v->tokens[i].type) {
                case INCREMENT:
                    count = 1;
                    while (i + 1 < v->count && v->tokens[i + 1].type == INCREMENT) {
                        count++;
                        i++;
                    }
                    instr.type = IR_ADD;
                    instr.operand = count;
                    instrVector_push(&vec, instr);
                    break;
                case DECREMENT:
                    count = -1;
                    while (i + 1 < v->count && v->tokens[i + 1].type == DECREMENT) {
                        count--;
                        i++;
                    }
                    instr.type = IR_ADD;
                    instr.operand = count;
                    instrVector_push(&vec, instr);
                    break;
                case LEFT:
                    count = -1;
                    while (i + 1 < v->count && v->tokens[i + 1].type == LEFT) {
                        count--;
                        i++;
                    }
                    instr.type = IR_MOVE;
                    instr.operand = count;
                    instrVector_push(&vec, instr);
                    break;
                case RIGHT:
                    count = 1;
                    while (i + 1 < v->count && v->tokens[i + 1].type == RIGHT) {
                        count++;
                        i++;
                    }
                    instr.type = IR_MOVE;
                    instr.operand = count;
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
                    if (i + 1 < v->count && i + 2 < v->count
                        && v->tokens[i + 2].type == END &&
                        (v->tokens[i + 1].type == INCREMENT || v->tokens[i + 1].type == DECREMENT)) {
                        instr.type = SET_ZERO;
                        instr.operand = 0;
                        i = i + 2;
                    }
                    else {
                        instr.type = IR_START;
                        instr.operand = 0;
                    }
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
    }
    if (level >= 2) {

    }
    if (level == 3) {

    }
    return vec;
}