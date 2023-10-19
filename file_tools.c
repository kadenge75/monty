#include "monty.h"
#include <ctype.h>

void open_file(char *file_name) {
    FILE *file = fopen(file_name, "r");

    if (file == NULL) {
        err(ERR_CANNOT_OPEN_FILE, file_name);
    }

    read_file(file);
    fclose(file);
}

void read_file(FILE *file) {
    char *line = NULL;
    size_t len = 0;
    int line_number = 1;
    int format = 0;

    while (getline(&line, &len, file) != -1) {
        format = parse_line(line, line_number, format);
        line_number++;
    }

    free(line);
}

int parse_line(char *line, int line_number, int format) {
    char *opcode, *value;
    const char *delim = "\n ";

    opcode = strtok(line, delim);
    if (opcode == NULL) {
        return format;
    }

    value = strtok(NULL, delim);

    if (strcmp(opcode, "stack") == 0) {
        return 0;
    }

    if (strcmp(opcode, "queue") == 0) {
        return 1;
    }

    find_func(opcode, value, line_number, format);
    return format;
}

void find_func(char *opcode, char *value, int line_number, int format) {
    instruction_t instructions[] = {
        {"push", push_func},
        {"pall", pall_func},
        {"pint", pint_func},
        {"pop", pop_func},
        {"nop", nop_func},
        // Add other instructions here
        {NULL, NULL}
    };

    if (opcode[0] == '#') {
        return;
    }

    for (int i = 0; instructions[i].opcode != NULL; i++) {
        if (strcmp(opcode, instructions[i].opcode) == 0) {
            call_func(instructions[i].func, opcode, value, line_number, format);
            return;
        }
    }

    err(ERR_INVALID_INSTRUCTION, line_number, opcode);
}

void call_func(op_func func, char *opcode, char *value, int line_number, int format) {
    if (strcmp(opcode, "push") == 0) {
        if (value == NULL || (!isdigit(value[0]) && (value[0] != '-' || !isdigit(value[1])))) {
            err(ERR_INVALID_PUSH_ARGUMENT, line_number);
        }
        int val = atoi(value);
        if (format == 0) {
            push_func(&stack, val);
        } else {
            push_queue(&queue, val);
        }
    } else {
        func(&stack, line_number);
    }
}
