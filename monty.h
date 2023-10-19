#ifndef MONTY_H
#define MONTY_H

/* Includes */
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/* Data Structures */
typedef struct stack_s {
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

typedef struct instruction_s {
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* External Global Variable */
extern stack_t *head;

/* Function Prototypes */
void open_file(char *file_name);
int parse_line(char *buffer, int line_number, int format);
void read_file(FILE *file);
int len_chars(FILE *file);
void find_func(char *opcode, char *value, int line_number, int format);

/* Stack Operations */
stack_t *create_node(int n);
void free_nodes(void);
void print_stack(stack_t **stack, unsigned int line_number);
void add_to_stack(stack_t **stack, unsigned int line_number);
void add_to_queue(stack_t **stack, unsigned int line_number);
void call_func(op_func func, char *opcode, char *value, int line_number, int format);
void print_top(stack_t **stack, unsigned int line_number);
void pop_top(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void swap_nodes(stack_t **stack, unsigned int line_number);
void add_nodes(stack_t **stack, unsigned int line_number);
void sub_nodes(stack_t **stack, unsigned int line_number);
void div_nodes(stack_t **stack, unsigned int line_number);
void mul_nodes(stack_t **stack, unsigned int line_number);
void mod_nodes(stack_t **stack, unsigned int line_number);
void print_char(stack_t **stack, unsigned int line_number);
void print_str(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);

/* Error Handling */
void err(int error_code, ...);
void more_err(int error_code, ...);
void string_err(int error_code, ...);

#endif /* MONTY_H */

