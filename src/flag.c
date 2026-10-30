#include "include/flag.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct conf flags = {
    .tape_size = 30000,
    .optimization = 1,
    .debug = false,
    .verbose = false,
    .trace = false,
    .wall = false,
    .strict = false,
    .interpret = false,
    .compile = true,
    .transpile = false,
    .output_file = "a.worm",
    .target = "x86_64",
    .input_file = NULL
};

void flags_init(int argc, char *argv[]) {
    for (int i = 1; i<argc; i += 2) {
        if (strcmp(argv[i],"--tape-size") == 0) {}
        else if (strcmp(argv[i], "-O0") == 0 || strcmp(argv[i], "-O1") == 0
            || strcmp(argv[i], "-O2") == 0|| strcmp(argv[i], "-O3") == 0){}
        else if (strcmp(argv[i], "-g") == 0 || strcmp(argv[i], "--debug") == 0) {}
        else if (strcmp(argv[i], "-v") == 0 || strcmp(argv[i], "--verbose") == 0) {}
        else if (strcmp(argv[i], "--trace") == 0){}
        else if (strcmp(argv[i], "-Wall") == 0){}
        else if (strcmp(argv[i], "--strict") == 0){}
        else if (strcmp(argv[i], "-r") == 0 || strcmp(argv[i], "--run") == 0){}
        else if (strcmp(argv[i], "-C") == 0 || strcmp(argv[i], "--compile") == 0){}
        else if (strcmp(argv[i], "-T") == 0 || strcmp(argv[i], "--transpile") == 0){}
        else if (strcmp(argv[i], "-o") == 0 || strcmp(argv[i], "--output") == 0){}
        else if (strcmp(argv[i], "-t") == 0 || strcmp(argv[i], "--target") == 0){}
        else{}
    }
}
