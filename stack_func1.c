#include "monty.h"


/**
 * add_to_stack - Pushes a new node onto the stack.
 *
 * This function creates a new node with the given data and adds it to the top
 * of the stack. The line number (ln) parameter is used for error handling and
 * reporting errors related to specific opcodes in the input file.
 *
 * @new_node: Pointer to the new node to be added to the stack.
 * @ln: Integer representing the line number of the corresponding opcode.
 */

void add_to_stack(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tmp = head;
	head = *new_node;
	head->next = tmp;
	tmp->prev = head;
}


/**
 * print_stack - Prints the elements of the stack.
 *
 * This function prints the integers stored in each node of the stack, starting
 * from the top node (head). The line_number parameter is not used in this
 * function and is included for consistency with other opcode functions.
 *
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Line number of the corresponding opcode (unused in this function).
 */

void print_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * pop_top - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void pop_top(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
		more_err(7, line_number);

	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}

/**
 * pop_top - Removes the top node from the stack.
 *
 * This function removes the top node from the stack. The line_number parameter
 * is used for error handling and reporting errors related to specific opcodes
 * in the input file.
 *
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the corresponding opcode.
 */

void print_top(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		more_err(6, line_number);
	printf("%d\n", (*stack)->n);
}
