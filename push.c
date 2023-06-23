#include "monty.h"

/**
* push - push an integer onto the stack
* @stack: double pointer to the stack
* @line_number: line number
*
* Return: nothing
*/

void push(stack_t **stack, unsigned int line_number)
{
    stack_t *new_node = NULL;
    char *token = NULL;
    int n = 0;

    token = strtok(NULL, " \n\t\r");
    if (token == NULL)
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    n = atoi(token);
    if (n == 0 && strcmp(token, "0") != 0)
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }

    new_node->n = n;
    new_node->prev = NULL;
    new_node->next = *stack;
    if (*stack != NULL)
        (*stack)->prev = new_node;
    *stack = new_node;
}
