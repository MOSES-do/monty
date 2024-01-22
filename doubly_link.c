#include "monty.h"
/**
* add_dnodeint_top - Function to add element ot the head of the stack
* @head: pointer to struct head
* @tail: pointer to add element to doubly linked list
* @n: integer value for struct
*/



void add_dnodeint_top(stack_t **head, stack_t *tail, const int n)
{
	stack_t *curr;

	tail->n = n;
	tail->prev = NULL;

	curr = *head;
	while (curr->prev != NULL)
	{
		curr = curr->prev;
	}
	curr->prev = tail;
	tail->next = curr;
	*head = tail;
}

/**
 * add_dnodeint - Function inserts 1st element into the linked list
 * @head: pointer to struct head
 * @n: integer value for struct
 */
void add_dnodeint(stack_t **head, const int n)
{
	stack_t *tail;

	tail = malloc(sizeof(stack_t));
	if (tail == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	if (*head != NULL)
	{
		add_dnodeint_top(head, tail, n);
	}
	else
	{
		tail->n = n;
		tail->prev = NULL;
		tail->next = NULL;
		*head = tail;
	}
}



