#include "monty.h"

/**
* pop - pops off the tail node
* Return: void
* @stack: the head of the stack
* @line_num: the line number
*/
void pop(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%i: can't pop an empty stack\n",
			line_num);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->next != NULL)
	{
/*		printf("------in the first else in pop\n");*/
		pop(&((*stack)->next), line_num);
		return;
	}
	else
	{
/*		printf("------- int the last else in pop\n");*/
		if ((*stack)->prev)
			tmp = (*stack)->prev;
		free(*stack);
		*stack = NULL;
		if (tmp)
			tmp->next = NULL;
	}
}
