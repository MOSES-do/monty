#include "monty.h"

/**
 * _push - calls the function that passes elements to the stack
 * @head: pointer to the head of the stack
 * @line_number: tracks line number of strings to be parsed
 */

void _push(stack_t **head, unsigned int line_number)
{
	int n, j;


	if (!glob.arg1)
	{
		fprintf(stderr, "L%u: ", line_number);
		fprintf(stderr, "usage: push integer\n");
		free_glob();
		exit(EXIT_FAILURE);
	}
	for (j = 0; glob.arg1[j] != '\0'; j++)
	{
		if (!isdigit(glob.arg1[j]) && glob.arg1[j] != '-')
		{
			fprintf(stderr, "L%u: ", line_number);
			fprintf(stderr, "usage: push integer\n");
			free_glob();
			exit(EXIT_FAILURE);
		}
	}

	n = atoi(glob.arg1);
	
	add_dnodeint(head, n);
}


/**
 * _pall - function prints all elements in the stack
 * @head: pointer to the head of the stack
 * @line_number: tracks line number of strings to be parsed
 */


void _pall(stack_t **head, unsigned int line_number)
{
	stack_t *pr;
	(void)line_number;
	for (pr = *head; pr != NULL; pr = pr->next)
		printf("%d\n", pr->n);
}

/**
 * _pint - function prints the head of the stack
 * @head: pointer to the head of the stack
 * @line_number: tracks line number of strings to be parsed
 */

void _pint(stack_t **head, unsigned int line_number)
{
	stack_t *tail;

	if (*head == NULL)
	{
		fprintf(stderr, "L%u: ", line_number);
		fprintf(stderr, "can't pint, stack empty\n");
		free_glob();
		exit(EXIT_FAILURE);
	}
	tail = *head;
	while (tail->prev != NULL)
		tail = tail->prev;
	printf("%d\n", tail->n);
}


/**
 * _pop - calls the function that passes elements to the stack
 * @head: pointer to the head of the stack
 * @line_number: tracks line number of strings to be parsed
 */

void _pop(stack_t **head, unsigned int line_number)
{
	stack_t *aux;

	if (*head == NULL || head == NULL)
	{
		fprintf(stderr, "L%u: ", line_number);
		fprintf(stderr, "can't pop an empty stack\n");
		free_glob();
		exit(EXIT_FAILURE);
	}
	aux = *head;
	*head = (*head)->next;
	free(aux);
}




/**
 * _swap - switch the top and 2nd element of the stack
 * @head: pointer to the head of the stack
 * @line_number: tracks line number of strings to be parsed
 */

void _swap(stack_t **head, unsigned int line_number)
{
	int run = 0, aux;
	stack_t *temp = NULL;

	temp = *head;

	while (temp)
	{
		temp = temp->next;
		run++;
	}
	if (run < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free_glob();
		exit(EXIT_FAILURE);
	}
	temp = *head;
	aux = temp->n;
	temp->n = temp->next->n;
	temp->next->n = aux;
}




