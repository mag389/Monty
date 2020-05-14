#include "monty.h"

/**
* pstr - puts the whole string
* Return: void
* @stack: the stack head
* @line_num: the line number of the file
*/
void pstr(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;

	(void) line_num;
	if (stack == NULL || *stack == NULL)
		printf("\n");
	else
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		pstrfromtail(&tmp, line_num);
	}
}
/**
* pstrfromtail - prints string from tail
* Return: void
* @stack: the stack tail/top
* @line_num: the line num in file
*/
void pstrfromtail(stack_t **stack, unsigned int line_num)
{
	(void) line_num;

	if (((*stack)->n >= 128) || (*stack)->n == 0)
	{
		printf("\n");
		return;
	}
	else
		printf("%c", (*stack)->n);
	if ((*stack)->prev)
		pstrfromtail(&((*stack)->prev), line_num);
	else
		printf("\n");
}
