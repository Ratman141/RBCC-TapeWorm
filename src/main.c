#include <stdio.h>
#include <stdbool.h>
#include "include/interpreter.h"
#include "include/codegen.h"
#include "include/flag.h"

// tapeworm <options> input_file
int main(int argc, char *argv[]) {

    printf("%d", argc);     // Check amount of args
    run_repl();
    if (argc == 1) {

    }
    flags_init(argc, argv);

    return 0;
}
