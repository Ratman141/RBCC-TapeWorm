#include "include/codegen.h"
#include "include/optimizer.h"
#include "include/flag.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void transpile(instrVector *vec, char* output) {
    FILE *f = fopen(output, "w");

    if (f == NULL) {
        printf("The file is not opened.");
        exit(EXIT_FAILURE);
    }

    fprintf(f, "#include <stdio.h>\n"
               "\nint main(void){\n"
               "\tint ptr = 0;\n"
               "\tunsigned char tape[%d] = {0};\n\n", flags.tape_size);

    size_t len = vec->count;
    size_t counter = 0;
    unsigned long long while_index = 1;
    while (counter < len) {
        switch (vec->instr[counter].type) {
            case IR_ADD:
                fprintf(f, "\ttape[ptr] += %llu;\n", vec->instr[counter].operand);
                break;
            case IR_MOVE:
                vec->instr[counter].operand = (vec->instr[counter].operand + 30000) % 30000;
                fprintf(f, "\tptr = (ptr + %llu) %% 30000;\n", vec->instr[counter].operand);
                break;
            case IR_OUT:
                fprintf(f, "\tputchar(tape[ptr]);\n");
                printf("\n");
                break;
            case IR_IN:
                fprintf(f, "\ttape[ptr] = getchar();\n");
                break;
            case SET_ZERO:
                fprintf(f, "\ttape[ptr] = 0;\n");
                break;
            case IR_START:
                fprintf(f, "\tint index%llu = ptr;\n"
                           "\twhile(tape[index%llu] != 0){\n", while_index, while_index);
                while_index++;
                break;
            case IR_END:
                fprintf(f, "\t}\n");
                break;
            case IR_EOF:
                goto eof;
            default:
                break;
        }
        counter++;
    }
    eof:
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