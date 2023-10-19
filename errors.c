#include "monty.h"
#include <stdarg.h>

void handle_error(int error_code, ...) {
    va_list args;
    va_start(args, error_code);

    switch (error_code) {
        case ERR_MISSING_FILE:
            fprintf(stderr, "USAGE: monty file\n");
            break;
        case ERR_CANNOT_OPEN_FILE:
            fprintf(stderr, "Error: Can't open file %s\n", va_arg(args, char *));
            break;
        case ERR_INVALID_INSTRUCTION:
            fprintf(stderr, "L%d: unknown instruction %s\n", va_arg(args, int), va_arg(args, char *));
            break;
        case ERR_MALLOC_FAILED:
            fprintf(stderr, "Error: malloc failed\n");
            break;
        case ERR_INVALID_PUSH_ARGUMENT:
            fprintf(stderr, "L%d: usage: push integer\n", va_arg(args, int));
            break;
        case ERR_EMPTY_STACK_PINT:
            fprintf(stderr, "L%d: can't pint, stack empty\n", va_arg(args, int));
            break;
        case ERR_EMPTY_STACK_POP:
            fprintf(stderr, "L%d: can't pop an empty stack\n", va_arg(args, int));
            break;
        case ERR_STACK_TOO_SHORT:
            fprintf(stderr, "L%d: can't %s, stack too short\n", va_arg(args, int), va_arg(args, char *));
            break;
        case ERR_DIVISION_BY_ZERO:
            fprintf(stderr, "L%d: division by zero\n", va_arg(args, int));
            break;
        case ERR_PCHAR_OUT_OF_RANGE:
            fprintf(stderr, "L%d: can't pchar, value out of range\n", va_arg(args, int));
            break;
        case ERR_EMPTY_STACK_PCHAR:
            fprintf(stderr, "L%d: can't pchar, stack empty\n", va_arg(args, int));
            break;
        default:
            break;
    }

    va_end(args);
    free_nodes();
    exit(EXIT_FAILURE);
}

