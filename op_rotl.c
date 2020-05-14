#include "monty.h"

/**
* rotl - rotate stack to top
* Return: void
* @stack: the stack to rotate
* @line_num: the line where rotl was called
*/
void rotl(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;
	int temp;

	(void) line_num;
	if (stack == NULL || *stack == NULL)
		return;

	tmp = *stack;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	temp = tmp->n;
	while (tmp->prev)
	{
		tmp->n = (tmp->prev)->n;
		tmp = tmp->prev;
	}
	(*stack)->n = temp;
}
