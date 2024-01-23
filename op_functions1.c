#include "monty.h"

/**
 * _add - function call adds two elements on the stack
 * @head: pointer to the head of the stack
 * @line_number: returns currentl line being parsed
 */

void _add(stack_t **head, unsigned int line_number)
{
	stack_t *curr;
	int sum = 0;

	curr = *head;

	if (curr == NULL && curr->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_glob();
		exit(EXIT_FAILURE);
	}
	sum = curr->n + curr->next->n;
	curr->next->n = sum;
	*(head) = curr->next;
	free(curr);
}

/**
 * _nop - function does nothing
 *  @head: pointer to the head of teh stack
 * @line_number: returns current string line
 */

void _nop(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;
}

