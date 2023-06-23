#include "monty.h"

/**
* pall - print values of stack
* @stack: double pointer to head
* @line_number: line number being executed
*
* Return: nothing
*/

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *head;

	(void)(line_number);

	head = *stack;
	while (head != NULL)
	{
		printf("%d\n", head->n);
		head = head->next;
	}
}
