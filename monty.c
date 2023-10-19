#include "monty.h"

/* Global variable declaration */
stack_t *head = NULL;

/* File operations */

void open_file(char *file_name) {
    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        err(2, file_name);
    }

    read_file(file);
    fclose(file);
}

int parse_line(char *buffer, int line_number, int format) {
    char *opcode, *value;
    const char *delim = "\n ";

    opcode = strtok(buffer, delim);
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

int len_chars(FILE *file) {
    int count = 0;
    int ch;
    while ((ch = fgetc(file)) != EOF) {
        count++;
    }
    return count;
}

void find_func(char *opcode, char *value, int line_number, int format) {
    /* Implementation of find_func goes here */
}

/* Stack operations */

stack_t *create_node(int n) {
    stack_t *node = malloc(sizeof(stack_t));
    if (node == NULL) {
        err(4);
    }
    node->n = n;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

void free_nodes(void) {
    stack_t *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void print_stack(stack_t **stack, unsigned int line_number) {
    /* Implementation of print_stack goes here */
}

/* Implementations of other stack operations go here */

void call_func(op_func func, char *opcode, char *value, int line_number, int format) {
    /* Implementation of call_func goes here */
}

/* Implementations of other functions go here */

