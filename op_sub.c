#include "monty.h"

/**
* sub - subtracts top two stack elements
* Return: void
* @stack: the stack
* @line_num: the line number
*/
void sub(stack_t **stack, unsigned int line_num)
{
	if (stack == NULL || *stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%i: can't sub, stack too short\n",
			line_num);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next)
	{
		if ((*stack)->next->next)
			sub(&((*stack)->next), line_num);
		else
		{
			(*stack)->n -= (*stack)->next->n;
			pop(stack, line_num);
		}
	}
	else
	{
		dprintf(STDERR_FILENO, "L%i: can't sub, stack too short\n",
			line_num);
		exit(EXIT_FAILURE);
	}
}
