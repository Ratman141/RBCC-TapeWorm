#ifndef TAPEWORM_LEXER_H
#define TAPEWORM_LEXER_H

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

token_t tokenize(char *src);
#endif //TAPEWORM_LEXER_H
