#include "monty.h"

/**
* pchar - prints char at the top of the stack
* Return: void
* @stack: he head of the stck
* @line_num: the current line number
*/
void pchar(stack_t **stack, unsigned int line_num)
{
	if (*stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%i: can't pchar, stack empty\n",
			line_num);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->next == NULL)
		if ((*stack)->n < 128)
			printf("%c\n", (*stack)->n);
		else
		{
			dprintf(STDERR_FILENO,
				"L%i: can't pchar, value out of range\n",
				line_num);
			exit(EXIT_FAILURE);
		}
	else
		pchar(&((*stack)->next), line_num);
}
