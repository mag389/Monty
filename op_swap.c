#include "monty.h"

/**
* swap - swaps top two elements
* Return: void
* @stack: the stack of data
* @line_num: the line number of the command
*/
void swap(stack_t **stack, unsigned int line_num)
{
	int temp;

	if (stack == NULL || *stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%i: can't swap, stack too short\n",
				line_num);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next)
	{
		if (((*stack)->next)->next)
			swap(&(*stack)->next, line_num);
		else
		{
			temp = (*stack)->n;
			(*stack)->n = (*stack)->next->n;
			(*stack)->next->n = temp;
		}
	}
	else
	{
		dprintf(STDERR_FILENO, "L%i: can't swap, stack too short\n",
			line_num);
		exit(EXIT_FAILURE);
	}
}
