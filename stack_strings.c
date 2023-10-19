#include "monty.h"
/**
 * print_char - Prints the ASCII character represented by the top element of the stack.
 *
 * This function prints the ASCII character corresponding to the integer value
 * stored in the top node of the stack. If the integer is a valid ASCII value,
 * the corresponding character is printed. The @stack parameter points to a
 * pointer pointing to the top node of the stack. The @line_number parameter
 * is used for error handling and reporting errors related to specific opcodes
 * in the input file.
 *
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the corresponding opcode.
 */

void print_char(stack_t **stack, unsigned int line_number)
{
	int ascii;

	if (stack == NULL || *stack == NULL)
		string_err(11, line_number);

	ascii = (*stack)->n;
	if (ascii < 0 || ascii > 127)
		string_err(10, line_number);
	printf("%c\n", ascii);
}

/**
 * print_str - Prints the string represented by ASCII values in the stack until a NULL terminator is encountered.
 *
 * This function interprets the integers stored in the stack as ASCII values and
 * prints the corresponding characters until a NULL terminator (0) is encountered.
 * The @stack parameter points to a pointer pointing to the top node of the stack.
 * The @line_number parameter is used for error handling and reporting errors
 * related to specific opcodes in the input file.
 *
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @ln: Integer representing the line number of the corresponding opcode.
 */

void print_str(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	int ascii;
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	tmp = *stack;
	while (tmp != NULL)
	{
		ascii = tmp->n;
		if (ascii <= 0 || ascii > 127)
			break;
		printf("%c", ascii);
		tmp = tmp->next;
	}
	printf("\n");
}

/**
 * rotl - Rotates the first node of the stack to the bottom.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void rotl(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}


/**
 * rotr - Rotates the last node of the stack to the top.
 *
 * This function moves the last node of the stack to the top, removing it from
 * its current position and placing it at the front of the stack. The @stack
 * parameter points to a pointer pointing to the top node of the stack. The
 * @ln parameter represents the line number of the corresponding opcode and
 * is used for error handling.
 *
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @ln: Integer representing the line number of the corresponding opcode.
 */

void rotr(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;

	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	(*stack)->prev = tmp;
	(*stack) = tmp;
}
