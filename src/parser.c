#include "include/parser.h"
#include <stdlib.h>

indexSet set_init(const vector *v) {
    indexSet set;
    set.set = malloc(v->size * sizeof(int));
    set.size = v->size;
    for (int i = 0; i < set.size; i++) {
        set.set[i] = -1;
    }
    return set;
}

void set_free(indexSet *set) {
    free(set);
    set->set = NULL;
    set->size = 0;
}

void parse(vector *v, indexSet *set) {

}