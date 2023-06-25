#include "monty.h"

/**
* get_op - checks for op in valid opcodes
* @op: the op to be checked
* @stack: double pointer to the beginning
* @line_number: line number
*
* Return: nothing
*/

void get_op(char *op, stack_t **stack, unsigned int line_number)
{
	size_t m;
	instruction_t valid_ops[] = {
		{"push", push};
		{"pall", pall};
		{"pint", pint};
		{"pop", pop};
		{"swap", swap};
		{"add", add};
		{"nop", nop};
		{"sub", sub};
		{"div", div};
		{"mul", mul};
		{"mod", mod};
		{NULL, NULL}
	};

	for (m = 0; valid_ops[m].opcode != NULL; m++)
	{
		if (strcmp(valid_ops[m].opcode, op) == 0)
		{
			valid_ops[m].f(stack, line_number);
			return;
		}
	}

	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, op);
	exit(EXIT_FAILURE);
}
