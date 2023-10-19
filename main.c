#include "monty.h"

/**
 * main - entry point
 * @argc: arguments count
 * @argv: list of arguments
 * Return: always 0
 */
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    open_file(argv[1]);
    free_nodes();

    return 0;
}

/**
 * create_node - Creates a new stack node.
 * @n: Number to be stored in the node
 * Return: A pointer to the newly created node, or NULL on failure.
 */
stack_t *create_node(int n) {
    stack_t *node = malloc(sizeof(stack_t));
    if (node == NULL) {
        err(ERR_MALLOC_FAILED);
    }
    node->n = n;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

/**
 * free_nodes - Frees all nodes in the stack.
 */
void free_nodes(void) {
    stack_t *tmp;

    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

/**
 * add_to_queue - Adds a new node to the queue.
 * @new_node: Pointer to the new node.
 * @ln: line number of the opcode (unused in this function).
 */
void add_to_queue(stack_t **new_node, __attribute__((unused)) unsigned int ln) {
    stack_t *tmp = head;

    if (new_node == NULL || *new_node == NULL) {
        exit(EXIT_FAILURE);
    }

    if (tmp == NULL) {
        head = *new_node;
    } else {
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = *new_node;
        (*new_node)->prev = tmp;
    }
}
