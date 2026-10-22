#include "include/interpreter.h"
#include "include/lexer.h"
#include "include/flag.h"
#include <stdio.h>
#include <string.h>

void interpret(const instrVector *vec, unsigned char *tape, int *index){
    size_t len = vec->count;
    size_t counter = 0;
    while (counter < len) {
        switch (vec->instr[counter].type) {
            case IR_ADD:
                tape[*index] += vec->instr[counter].operand;
                break;
            case IR_MOVE:
                *index += vec->instr[counter].operand;
                break;
            case IR_OUT:
                putchar(tape[*index]);
                printf("\n");
                break;
            case IR_IN:
                tape[*index] = getchar();
                int c;                              // So far works, maybe look into it in the future
                while ((c = getchar()) != '\n') {}  // Doesnt skip iteration in REPL
                break;
            case SET_ZERO:
                tape[*index] = 0;
                break;
            case IR_START:
                if (tape[*index] == 0) {
                    counter = vec->instr[counter].operand;
                }
                break;
            case IR_END:
                if (tape[*index] != 0) {
                    counter = vec->instr[counter].operand;
                }
                break;
            case IR_EOF:
                return;
            default:
                break;
        }
        counter++;
    }
}

void run_repl() {
    printf("TapeWorm    |   1.0.0   |   Ratman141\n");
    char input[1024];
    unsigned char tape[30000] = {0};
    int ptr = 0;
    while (1) {
        printf(">>>");
        fflush(stdout);

        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;
        }
        if (strcmp(input, "exit\n") == 0) {
            break;
        }

        vector v = tokenize(input);
        parse(&v);
        instrVector vec = optimize(flags.optimization, &v);

        interpret(&vec, tape, &ptr);

        vector_free(&v);
        instrVector_free(&vec);
    }
}

/*
 *
 *vector v = tokenize(x);
 *indexSet set = set_init(v);
 *instrVector vec = optimize(1, v, set);
 *
 *interpret(vec, set, tape, index);
 *
 *vector_free(v);
 *set_free(set);
 *instrVector_free(vec);
 */