#include "include/parser.h"
#include <stdlib.h>
#include <stdio.h>

void parse(vector *v) {
    size_t len = v->count;
    int *stack = malloc(len * sizeof(int));
    int stackIndex = 0;
    for (int i = 0; i < len; i++) {
        if (v->tokens[i].type == START) {
            stack[stackIndex++] = i;
        }
        else if (v->tokens[i].type == END) {
            if (stackIndex == 0) {
                fprintf(stderr, "[ERROR] Syntax Error\n");
                free(stack);
                vector_free(v);
                exit(1);
            }
                int startIndex = stack[--stackIndex];
                v->tokens[startIndex].pos = i;
                v->tokens[i].pos = startIndex;
        }
    }
    if (stackIndex != 0) {
        fprintf(stderr, "[ERROR] Syntax Error\n");
        free(stack);
        vector_free(v);
        exit(1);
    }
    free(stack);
}