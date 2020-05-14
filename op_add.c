#include "monty.h"

/**
* add - adds top two stack elements
* Return: void
* @stack: the stack
* @line_num: the line number
*/
void add(stack_t **stack, unsigned int line_num)
{
	if (stack == NULL || *stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%i: can't add, stack too short\n",
			line_num);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next)
	{
		if ((*stack)->next->next)
			add(&((*stack)->next), line_num);
		else
		{
			(*stack)->n += (*stack)->next->n;
			pop(stack, line_num);
		}
	}
	else
	{
		dprintf(STDERR_FILENO, "L%i: can't add, stack too short\n",
			line_num);
		exit(EXIT_FAILURE);
	}
}
