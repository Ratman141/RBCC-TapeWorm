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
} TokenVector;

void TokenVector_init(TokenVector *v);

void TokenVector_free (TokenVector *v);

void TokenVector_push (TokenVector *v, token_t t);

TokenVector tokenize(char *src);
#endif //TAPEWORM_LEXER_H
