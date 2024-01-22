
#include "monty.h"
/**
 * get_op_func - function that calls f(*p)
 * @ops: checker to call function
 * Return: success
*/

void (*get_op_func(char *ops))(stack_t **, unsigned int)
{
	int i = 0;
	instruction_t arrOp[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{NULL, NULL}
	};

	for (i = 0; arrOp[i].opcode; i++)
	{
		if (strcmp(arrOp[i].opcode, ops) == 0)
		{
			return (arrOp[i].f);
		}
	}

	fprintf(stderr, "L%u: ", glob.cont);
	fprintf(stderr, "unknown instruction %s\n", ops);
	free_glob();
	exit(EXIT_FAILURE);

}

