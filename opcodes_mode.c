#include "monty.h"

/**
 * addst - Changes mode of push to stack.
 *
 * This function changes the mode of the `push` operation to stack mode.
 * It takes a pointer to the stack and the line number as parameters.
 *
 * @stack: Pointer to the stack.
 * @nline: Line number.
 * 
 * Return: Nothing.
 */

void addst(stack_t **stack, unsigned int nline)
{
	(void)nline;
	(void)stack;

	arg.flag = 0;
}

/**
 * addqu - changes mode of push to queue
 * @stack: pointer to stack
 * @nline: line number
 *
 * Return: Nothing.
 */
void addqu(stack_t **stack, unsigned int nline)
{
	(void)nline;
	(void)stack;

	arg.flag = 1;
}
