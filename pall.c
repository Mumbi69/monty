#include "monty.h"

/**
* push - pushes an element to the stack
* @stack: double pointer to the head of the stack
* @line_number: line number in the file
*/

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	char *token;
	int number;

	token = strtok(NULL, " \n");
	if (token == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	number = atoi(token);

	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = number;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}

/**
* pall - prints all the values on the stack
* @stack: double pointer to the head of the stack
* @line_number: line number in the file
*/

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
	(void)line_number;
}

/**
* get_op_func - searches for the opcode and returns the corresponding function
* @opcode: opcode to search for
*
* Return: pointer to the corresponding function, or NULL if opcode not found
*/

void (*get_op_func(char *opcode))(stack_t **stack, unsigned int line_number)
{
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	int i = 0;

	while (instructions[i].opcode != NULL)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
			return (instructions[i].f);
		i++;
	}

	return (NULL);
}

/**
* main - entry of a program
*
* Return: nothing
*/

int main(void)
{
	char *opcode = "push";
	stack_t *stack = NULL;
	unsigned int line_number = 1;

void (*op_func)(stack_t **stack, unsigned int line_number)
	 = get_op_func(opcode);

	if (op_func != NULL)
		op_func(&stack, line_number);

	return (0);
}
