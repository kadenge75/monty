#include "monty.h"
/**
 * mul_nodes - Multiplies the top two elements of the stack.
 *
 * This function multiplies the top element of the stack with the second element
 * from the top and stores the result in the second element. It removes the top
 * element from the stack. The @stack parameter points to a pointer pointing to
 * the top node of the stack. The @line_number parameter is used for error
 * handling and reporting errors related to specific opcodes in the input file.
 *
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the corresponding opcode.
 */
void mul_nodes(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "mul");

	(*stack) = (*stack)->next;
	sum = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * mod_nodes - Computes the modulus of the second element from the top by the top element of the stack.
 *
 * This function computes the modulus (remainder) of the second element from the top
 * of the stack by the top element of the stack and stores the result in the second
 * element. It removes the top element from the stack. The @stack parameter points
 * to a pointer pointing to the top node of the stack. The @line_number parameter
 * is used for error handling and reporting errors related to specific opcodes in the input file.
 *
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the corresponding opcode.
 */

void mod_nodes(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_err(8, line_number, "mod");


	if ((*stack)->n == 0)
		more_err(9, line_number);
	(*stack) = (*stack)->next;
	sum = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
