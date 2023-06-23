#include "monty.h"

/**
* m_pall - print all values on stack
* @stack: double pointer
* @line_number: line number being executed
*
* Return: nothing
*/

void m_pall(stack_t **stack, unsigned int line_number)
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
