#include "monty.h"
/**
 * addnode - Adds a node to the head of the stack.
 *
 * This function adds a new node with the given value `n` to the head of the stack.
 * It takes the current head of the stack and the new value `n` as parameters.
 *
 * @head: Pointer to the head of the stack.
 * @n: New value to be stored in the node.
 *
 * Return: No return.
 */

void addnode(stack_t **head, int n)
{

	stack_t *new_node, *aux;

	aux = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{ printf("Error\n");
		exit(0); }
	if (aux)
		aux->prev = new_node;
	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}
