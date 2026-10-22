#include "include/codegen.h"
#include "include/flag.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void transpile(instrVector *vec, char* output) {
    FILE *f = fopen(output, "w");

    fprintf(f, "#include <stdio.h>\n"
               "\nint main(void){\n"
               "\tchar tape[%d];\n", flags.tape_size);

    if (f == NULL) {
        printf("The file is not opened.");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < vec->size; i++) {
        switch (vec->instr[i].type) {
            case IR_ADD:
                break;
            case IR_MOVE:
                break;
            case IR_OUT:
                break;
            case IR_IN:
                break;
            case IR_START:
                break;
            case IR_END:
                break;
            case SET_ZERO:
                break;
            case IR_EOF:
                break;
            default:
                break;
        }
    }
    fprintf(f, "\treturn 0;\n}");
    fclose(f);
}

// [HEADER]
// [VERSION]
// [BINARY/HEX]
//
// [OPCODE][OPERAND]
// 3-BIT   32-BIT
// 000-111
// 8 combinations