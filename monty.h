#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>


/*
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/*
 * struct global_v - Global variables for monty program
 * @arg: char pointer  to instruction for f(*p)
 * @arg1: integer variable to store token2 (number)
 * @head: pointer to stack_t head
 */
typedef struct global_v
{
	char *arg;
	char *arg1;
	FILE *file;
	stack_t *head;
	char buffer[512];
	unsigned int cont;
} global_v;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/*doubly linked list prototype*/
void add_dnodeint(stack_t **head, const int n);

/*call function*/
void _push(stack_t **head, unsigned int f_line);
void _pall(stack_t **head, unsigned int f_line);
void _pint(stack_t **head, unsigned int f_line);
void _pop(stack_t **head, unsigned int f_line);
void _swap(stack_t **head, unsigned int f_line);
void _add(stack_t **head, unsigned int f_line);
void _nop(stack_t **head, unsigned int f_line);

void (*get_op_func(char *ops))(stack_t **, unsigned int);



extern global_v glob;


void free_glob(void);
char *parse_input(char *args, unsigned int linecount);

/*free stack head*/
void deallocate(void);
#endif

