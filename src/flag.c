#include "include/flag.h"
#include <stdlib.h>

struct conf flags = {
    .tape_size = 30000,
    .optimization = 1,
    .debug = false,
    .verbose = false,
    .trace = false,
    .wall = false,
    .strict = false,
    .interpret = false,
    .compile_only = false,
    .output_file = "a.worm",
    .target = "x86_64",
    .input_file = NULL
};

void flags_init(int argc, char *argv[]) {

}
