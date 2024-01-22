#include "monty.h"

/**
 * deallocate - Function to deallocate allocated memory blocks
 */

void deallocate(void)
{
	stack_t **head, *aux, *curr;

	head = &glob.head;
	curr = *head;
	while (curr != NULL)
	{
		aux = curr;
		curr = curr->next;
		free(aux);
	}
	head = NULL;
}
