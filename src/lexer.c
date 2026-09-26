#include "include/lexer.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void vector_init(vector *v) {
    v->tokens = NULL;
    v->size = 0;
    v->count = 0;
}

void vector_free (vector *v) {
    free(v->tokens);
    v->tokens = NULL;
}

void vector_push (vector *v, token_t t) {
    if (v->count == v->size) {
        size_t size = v->size < 8 ? 8 : v->size * 2;
        void *temp = realloc(v->tokens, size * sizeof(token_t));
        if (!temp) {
            fprintf(stderr, "[FATAL] Out of memory\n");
            vector_free(v);
            exit(1);
        }
        v->tokens = temp;
        v->size = size;
    }
    v->tokens[v->count++] = t;
}


vector tokenize(const char *src) {
    vector v;
    vector_init(&v);
    token_t temp;
    size_t len = strlen(src);
    for (int i = 0; i<len; i++) {
        switch (src[i]) {
            case '+':
                temp.type = INCREMENT;
                vector_push(&v, temp);
                break;
            case '-':
                temp.type = DECREMENT;
                vector_push(&v, temp);
                break;
            case '<':
                temp.type = LEFT;
                vector_push(&v, temp);
                break;
            case '>':
                temp.type = RIGHT;
                vector_push(&v, temp);
                break;
            case '.':
                temp.type = OUT;
                vector_push(&v, temp);
                break;
            case ',':
                temp.type = IN;
                vector_push(&v, temp);
                break;
            case '[':
                temp.type = START;
                vector_push(&v, temp);
                break;
            case ']':
                temp.type = END;
                vector_push(&v, temp);
                break;
            default:
                // Nothing in here
                break;
        }
    }
    temp.type = EOF_TOKEN;
    vector_push(&v, temp);
    return v;
}