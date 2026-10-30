#include <stdio.h>
#include <string.h>
#include "include/interpreter.h"
#include "include/codegen.h"
#include "include/flag.h"

#define VERSION "1.0.0"

// tapeworm <options> input_file
int main(int argc, char *argv[]) {
    if (argc == 1) {
        printf("Not enough arguments\n");
        return(1);
    }
    if (strcmp(argv[1], "--help") == 0) {
        printf("Usage: TapeWorm <options> file...\n");
        printf("Options:\n");
        printf("\t--tape-size <n>\tSet tape size\n");
        printf("\t-O<level>\tSet optimization level\n");
        printf("\t-g | --debug\tEnable debug mode\n");
        printf("\t-v | --verbose\tDisplay more detailed information during execution\n");
        printf("\t--trace\tEnable detailed execution tracing\n");
        printf("\t-Wall\tEnable all compiler warnings\n");
        printf("\t--strict\tEnable strict mode\n");
        printf("\t-r | --run\tInterpret and execute code without compiling\n");
        printf("\t-C | --compile-only\tCompile the source without executing\n");
        printf("\t-o | --output <file>\tSpecify the name of the output file\n");
        printf("\t-t | --target <arch>\tSpecify target architecture\n");
        return 0;
    }
    if (strcmp(argv[1], "--version") == 0) {
        printf("TapeWorm (RBCC) version %s\n", VERSION);
        return 0;
    }
    flags_init(argc, argv);

    printf("%d", argc);     // Check amount of args
    //run_repl();
    char input[128];
    if (fgets(input, 128, stdin) == NULL) return 1;
    vector v = tokenize(input);
    parse(&v);
    instrVector vec = optimize(flags.optimization, &v);

    transpile(&vec, "tape.c");

    vector_free(&v);
    instrVector_free(&vec);

    return 0;
}
