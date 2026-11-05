#include "include/flag.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct conf flags = {
    .tape_size = 30000,
    .optimization = 1,
    .wall = false,
    .interpret = false,
    .compile = true,
    .transpile = false,
    .output_file = "a.worm",
    .target = "x86_64",
    .input_file = NULL
};

void flags_init(int argc, char *argv[]) {
    for (int i = 1; i<argc; i++) {
        if (strcmp(argv[i],"--tape-size") == 0) {
            if (i + 1 >= argc) {
                fprintf(stderr, "Missing value for --tape-size\n");
                exit(EXIT_FAILURE);
            }
            flags.tape_size = strtol(argv[i+1], NULL, 10);
            i++;
        }
        else if (argv[i][0] == '-' && argv[i][1] == 'O') {
            if (argv[i][2] == '0') flags.optimization = 0;
            else if (argv[i][2] == '1') flags.optimization = 1;
            else if (argv[i][2] == '2') flags.optimization = 2;
            else if (argv[i][2] == '3') flags.optimization = 3;
            else {
                fprintf(stderr, "Invalid optimization level: %s\n", argv[i]);
                exit(EXIT_FAILURE);
            }
        }
        else if (strcmp(argv[i], "-Wall") == 0) {
            flags.wall = true;
        }
        else if (strcmp(argv[i], "-r") == 0 || strcmp(argv[i], "--run") == 0) {
            if (flags.compile) flags.compile = false;
            if (flags.transpile) flags.transpile = false;
            flags.interpret = true;
        }
        else if (strcmp(argv[i], "-C") == 0 || strcmp(argv[i], "--compile") == 0) {
            if (flags.interpret) flags.interpret = false;
            if (flags.transpile) flags.transpile = false;
            flags.compile = true;
        }
        else if (strcmp(argv[i], "-T") == 0 || strcmp(argv[i], "--transpile") == 0) {
            if (flags.interpret) flags.interpret = false;
            if (flags.compile) flags.compile = false;
            flags.transpile = true;
            if (strcmp(flags.output_file, "a.worm") == 0) flags.output_file = "worm.c";
            printf("%s\n", flags.output_file);
            printf("%d\n", flags.transpile);
        }
        else if (strcmp(argv[i], "-o") == 0 || strcmp(argv[i], "--output") == 0) {
            if (i + 1 >= argc) {
                fprintf(stderr, "Missing value for -o / --output\n");
                exit(EXIT_FAILURE);
            }
            flags.output_file = argv[i + 1];
            i++;
        }
        else if (strcmp(argv[i], "-t") == 0 || strcmp(argv[i], "--target") == 0) {
            if (i + 1 >= argc) {
                fprintf(stderr, "Missing value for -t / --target\n");
                exit(EXIT_FAILURE);
            }
            flags.target = argv[i + 1];
            i++;
        }
        else {
            if (argv[i][0] != '-') {
                if (flags.input_file != NULL) {
                    fprintf(stderr, "Multiple input files provided\n");
                    exit(EXIT_FAILURE);
                }

                flags.input_file = argv[i];
            }

        }
    }
}
