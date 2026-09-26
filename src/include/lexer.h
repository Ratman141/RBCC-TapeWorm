#ifndef TAPEWORM_LEXER_H
#define TAPEWORM_LEXER_H

#include <stddef.h>

typedef enum{
    INCREMENT,      // +
    DECREMENT,      // -
    LEFT,           // <
    RIGHT,          // >
    OUT,            // .
    IN,             // ,
    START,          // [
    END,            // ]
    EOF_TOKEN
}TokenType;

typedef struct {
    TokenType type;
}token_t;

typedef struct {
    token_t *tokens;
    size_t count;
    size_t size;
} vector;

void vector_init(vector *v);

void vector_free (vector *v);

void vector_push (vector *v, token_t t);

vector tokenize(const char *src);
#endif //TAPEWORM_LEXER_H
