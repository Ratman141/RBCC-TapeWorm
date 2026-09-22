#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct {
    int tape_size;      // --tape-size <n>
    int cell_size;      // --cell-size <8/16/32>
    int optimization;   // -00, -01, -02, -03
    bool debug;         // -g, --debug
    bool verbose;       // -v, --verbose
    bool trace;         // --trace
    bool wall;          // -Wall
    bool strict;        // --strict
    bool wrap;          // --no-wrap
    bool interpret;     // -r, --run
    bool compile_only;  // -C, --compile-only
    char *output_file;  // -o, --output <file>
    char *target;       // -t, --target <arch>
    char *input_file;
}flags;

void flags_init(void) {
    flags.tape_size = 30000;
    flags.cell_size = 8;
    flags.optimization = 1;
    flags.debug = false;
    flags.verbose = false;
    flags.trace = false;
    flags.wall = true;
    flags.strict = false;
    flags.wrap = true;
    flags.interpret = false;
    flags.compile_only = true;
    flags.output_file = "a.worm";
    flags.target = "x86_64";
}

// if interpret and compile_only are false then it compiles and runs

int main(int argc, char *argv[]) {
    flags_init();

    printf("%d", argc);
    if (argc == 1) {

    }
    FILE* fptr;
    return 0;
}
