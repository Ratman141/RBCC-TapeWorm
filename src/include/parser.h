#ifndef TAPEWORM_PARSER_H
#define TAPEWORM_PARSER_H

#include "lexer.h"

typedef struct {
    int *set;
    size_t size;
}indexSet;

indexSet set_init(const vector *v);

void set_free(indexSet *set);

void parse(vector *v, indexSet *set);

#endif //TAPEWORM_PARSER_H
