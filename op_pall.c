#include "monty.h"

/**
* free_stack_t - frees doubly linked lists to not leak mem
* Return: nothing
* @head: head node of the list
*/
void free_stack_t(stack_t *head)
{
	if (head == NULL)
		return;
	if (!head->next)
		free(head);
	else
	{
		free_stack_t(head->next);
		free(head);
	}
}
