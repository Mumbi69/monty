#include "monty.h"
#include <ctype.h>


/**
* push - push an integer onto the stack
* @stack: double pointer to the stack
* @line_number: line number
*
* Return: nothing
*/

void push(stack_t **stack, unsigned int line_number)
{
	char *arg;
	int n;

	arg = strtok(NULL, "\n\t\r ");
	if (arg == NULL || check_for_digit(arg))
	{
		dprintf(STDOUT_FILENO,
			"L%u: usage: push integer\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	n = atoi(arg);
	push2(stack, n);
}

/**
* check_for_digit - checks that a string only contains digits
* @arg: string to check
*
* Return: 0 if only digits, else 1
*/

static int check_for_digit(char *arg)
{
	int i;

	for (i = 0; arg[i]; i++)
	{
		if (arg[i] == '-' && i == 0)
			continue;
		if (isdigit(arg[i]) == 0)
			return (1);
	return (0);
}
