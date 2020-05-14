#include "monty.h"

/**
* free_stack_t - frees doubly linked lists to not leak mem
* Return: nothing
* @head: head node of the list
*/
void free_stack_t(stack_t **head)
{
	if (head == NULL || *head == NULL)
		return;
	if (!(*head)->next)
		free(*head);
	else
	{
		free_stack_t(&((*head)->next));
		free(*head);
	}
}

/**
* pall - prints list
* @stack: the head of the list
* @line_num: the line number of the original file
* Return: void
*/
void pall(stack_t **stack, unsigned int line_num)
{
	(void) line_num;

	if (stack == NULL || (*stack) == NULL)
		return;
	pall(&((*stack)->next), line_num);
	printf("%i\n", (*stack)->n);
}
