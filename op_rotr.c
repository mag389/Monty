#include "monty.h"

/**
* rotr - rotate stack to bottom
* Return: void
* @stack: the stack to rotate
* @line_num: the line where rotl was called
*/
void rotr(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;
	int temp;

	(void) line_num;
	if (stack == NULL || *stack == NULL)
		return;

	tmp = *stack;
	temp = tmp->n;
	while (tmp->next)
	{
		tmp->n = (tmp->next)->n;
		tmp = tmp->next;
	}
	tmp->n = temp;
}
