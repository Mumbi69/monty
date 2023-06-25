#include <stdio.h>
#include "monty.h"

/**
* main - start of monty program
* @argc: counts number of arguments passed
* @argv: array of argument strings
* Return: nothing
*/

int main(int argc, char *argv[])
{
	FILE *fptr = NULL;
	size_t *m = 0;
	char **mystring = NULL, *op = NULL;
	stack_t *stack = NULL;
	unsigned int line_number = 0;

	/*hold flag info, whether monty is on queue or stack mode*/
	var.queue = 0;
	var.stack_len = 0;

	if (arg != 2)
	{
		fprintf(stderr, "USAGE: monty file\n")
		exit(EXIT_FAILURE);
	}

	fptr = fopen(argv[1], "r");

	if (fptr == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", fptr);
		exit(EXIT_FAILURE);
	}

	/*freeing allocated resources when program exits*/
	on_exit(free_mystring, &mystring);
	on_exit(free_stack, &stack);
	on_exit(fptr_close, fptr);

	while (getline(&mystring, &m, fptr) != -1)
	{
		line_number++;
		op = strtok(mystring, "\n\t\r");
		if (op != NULL && op[0] != '#')
		{
			get_op(op, &stack, line_number);
		}
	}
	exit(EXIT_SUCCESS)
}

/**
* fptr_close - close file stream
* @status: status passed to exit
* @arg: pointer to file stream
*
* Return: nothing
*/

void fptr_close(int status, void *arg)
{
	FILE *fptr;

	(void)status;

	fptr = (FILE *) arg;
	fclose(fptr);
}











