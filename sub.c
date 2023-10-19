#include "monty.h"
/**
 * f_sub - Subtraction operation.
 *
 * This function performs subtraction on the top two elements of the stack.
 * It takes the stack's head and the line number as parameters.
 *
 * @head: Stack head.
 * @counter: Line number.
 *
 * Return: No return.
 */

void f_sub(stack_t **head, unsigned int counter)
{
	stack_t *aux;
	int sus, nodes;

	aux = *head;
	for (nodes = 0; aux != NULL; nodes++)
		aux = aux->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	aux = *head;
	sus = aux->next->n - aux->n;
	aux->next->n = sus;
	*head = aux->next;
	free(aux);
}
