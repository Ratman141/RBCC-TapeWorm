#include "include/parser.h"
#include <stdlib.h>
#include <stdio.h>

indexSet set_init(const vector *v) {
    indexSet set;
    set.set = malloc(v->count * sizeof(int));
    set.size = v->count;
    for (int i = 0; i < set.size; i++) {
        set.set[i] = -1;
    }
    return set;
}

void set_free(indexSet *set) {
    free(set->set);
    set->set = NULL;
    set->size = 0;
}

void parse(vector *v,  indexSet *set) {
    size_t len = set->size;
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
                set_free(set);
                vector_free(v);
                exit(1);
            }
                int startIndex = stack[--stackIndex];
                set->set[startIndex] = i;
                set->set[i] = startIndex;
        }
    }
    if (stackIndex != 0) {
        fprintf(stderr, "[ERROR] Syntax Error\n");
        free(stack);
        set_free(set);
        vector_free(v);
        exit(1);
    }
    free(stack);
}