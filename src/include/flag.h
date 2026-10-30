#ifndef TAPEWORM_FLAG_H
#define TAPEWORM_FLAG_H

#include <stdbool.h>

// if interpret and compile_only are false then it compiles and runs
struct conf{
    int tape_size;      // --tape-size <n>
    int optimization;   // -00, -01, -02, -03
    bool debug;         // -g, --debug
    bool verbose;       // -v, --verbose
    bool trace;         // --trace
    bool wall;          // -Wall
    bool strict;        // --strict
    bool interpret;     // -r, --run
    bool compile;  // -C, --compile
    bool transpile; //-T, --transpile
    char *output_file;  // -o, --output <file>
    char *target;       // -t, --target <arch>
    char *input_file;
};

extern struct conf flags;

void flags_init(int argc, char *argv[]);

#endif //TAPEWORM_FLAG_H
