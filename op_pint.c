#include "monty.h"

/**
* pint - prints value at the top of the stack
* Return: void
* @stack: he head of the stck
* @line_num: the current line number
*/
void pint(stack_t **stack, unsigned int line_num)
{
	if (*stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%i: can't pint, stack empty\n",
			line_num);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->next == NULL)
		printf("%i\n", (*stack)->n);
	else
		pint(&((*stack)->next), line_num);
}
