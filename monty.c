#include "monty.h"

global_v glob;
/**
 * free_glob - general variables function
 */

void free_glob(void)
{

	fclose(glob.file);
}

/**
 * start_glob - function initializes global variables
 * @fd: File descriptor
 */

void start_glob(FILE *fd)
{
	glob.arg = NULL;
	glob.file = fd;
	glob.head = NULL;
	glob.cont = 0;
}

/**
 * open_file - function chrcks if file is readable
 * @argc: Tracks number of arguments in the terminal
 * @argv: Array to store elements from terminal
 * Return: return on success
 */
FILE *open_file(int argc, char *argv[])
{
	FILE *fd;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");

	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	return (fd);
}


/**
 * main - Main Function collects data from file
 * @argc: Tracks number of arguments in the terminal
 * @argv: Array to store elements from terminal
 * Return: return 0 in success
 */
int main(int argc, char *argv[])
{
	FILE *fd;

	fd = open_file(argc, argv);

	start_glob(fd);

	while (fgets(glob.buffer,  sizeof(glob.buffer),  fd))
	{
		glob.cont++;
		parse_input(glob.buffer, glob.cont);
	}
	

	fclose(fd);
	deallocate();

	return (0);
}

