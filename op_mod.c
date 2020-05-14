#include "monty.h"

/**
* mod - mod top two stack elements
* Return: void
* @stack: the stack
* @line_num: the line number
*/
void mod(stack_t **stack, unsigned int line_num)
{
	if (stack == NULL || *stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%i: can't mod, stack too short\n",
			line_num);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next)
	{
		if ((*stack)->next->next)
			mod(&((*stack)->next), line_num);
		else
		{
			if ((*stack)->next->n != 0)
			{
				(*stack)->n %= (*stack)->next->n;
				pop(stack, line_num);
			}
			else
			{
			dprintf(STDERR_FILENO, "L%i: division by zero\n",
				line_num);
			exit(EXIT_FAILURE);
			}
		}
	}
	else
	{
		dprintf(STDERR_FILENO, "L%i: can't mod, stack too short\n",
			line_num);
		exit(EXIT_FAILURE);
	}
}
