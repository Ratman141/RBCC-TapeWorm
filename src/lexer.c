#include "include/lexer.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void TokenVector_init(TokenVector *v) {
    v->tokens = NULL;
    v->size = 0;
    v->count = 0;
}

void TokenVector_free (TokenVector *v) {
    free(v->tokens);
    v->tokens = NULL;
}

void TokenVector_push (TokenVector *v, token_t t) {
    if (v->count == v->size) {
        size_t size = v->size < 8 ? 8 : v->size * 2;
        void *temp = realloc(v->tokens, size * sizeof(token_t));
        if (!temp) {
            fprintf(stderr, "[FATAL] Out of memory\n");
            TokenVector_free(v);
            exit(1);
        }
        v->tokens = temp;
        v->size = size;
    }
    v->tokens[v->count++] = t;
}


TokenVector tokenize(char *src) {
    TokenVector v;
    TokenVector_init(&v);
    token_t temp;
    size_t len = strlen(src);
    for (int i = 0; i<len; i++) {
        switch (src[i]) {
            case '+':
                temp.type = INCREMENT;
                TokenVector_push(&v, temp);
                break;
            case '-':
                temp.type = DECREMENT;
                TokenVector_push(&v, temp);
                break;
            case '<':
                temp.type = LEFT;
                TokenVector_push(&v, temp);
                break;
            case '>':
                temp.type = RIGHT;
                TokenVector_push(&v, temp);
                break;
            case '.':
                temp.type = OUT;
                TokenVector_push(&v, temp);
                break;
            case ',':
                temp.type = IN;
                TokenVector_push(&v, temp);
                break;
            case '[':
                temp.type = START;
                TokenVector_push(&v, temp);
                break;
            case ']':
                temp.type = END;
                TokenVector_push(&v, temp);
                break;
            default:
                // Nothing in here
                break;
        }
    }
    temp.type = EOF_TOKEN;
    TokenVector_push(&v, temp);
    return v;
}