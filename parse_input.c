#include "monty.h"


/**
* parse_input - function to tokenize string inputs
* @args: String to be tokenized
* @linecount: line number of cureent string to be tokenized
* Return: 0 on success
*/

char *parse_input(char *args, unsigned int linecount)
{
	char *token, *tokens[2];
	size_t count = 0;
	(void)linecount;

	token = strtok(args, " \n\t");
	while (token != NULL)
	{
		tokens[count++] = token;
		token = strtok(NULL, " \n\t");
	}
	glob.arg = tokens[0];
	glob.arg1 = tokens[1];	
		
	get_op_func(tokens[0])(&glob.head, glob.cont);
	return (0);
}




