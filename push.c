#include "monty.h"

/**
* push - pushe an element to the stack
* @stack: ...
* @line_number: line number
* Return: success or failure
*/

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = NULL;
	int number = 0;

	if (global_var.arguments == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	number = atoi(global_var.arguments);
	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = number;
	new_node->prev = NULL;
	new_node->next = NULL;
	if (*stack == NULL)
	{
		*stack = new_node;
	}
	else
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
		*stack = new_node;
	}
}

/**
* pall - prints all thev values on the stack
* @stack: ...
* @line_number: line number
* Return : nothing
*/

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
