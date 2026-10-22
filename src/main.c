#include <stdio.h>
#include <stdbool.h>
#include "include/interpreter.h"
#include "include/codegen.h"
#include "include/flag.h"

// tapeworm <options> input_file
int main(int argc, char *argv[]) {

    printf("%d", argc);     // Check amount of args
    //run_repl();
    char input[128];
    vector v = tokenize(input);
    parse(&v);
    instrVector vec = optimize(flags.optimization, &v);

    transpile(&vec, "tape.c");

    vector_free(&v);
    instrVector_free(&vec);
    if (argc == 1) {

    }
    flags_init(argc, argv);

    return 0;
}
