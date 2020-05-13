#include "monty.h"

/**
* push - adds number to top of stack
* Return: void
* @stack: the stack to add to, double linked list
* @line_num: the line number in the original file
*/
void push(stack_t **stack, unsigned int line_num)
{
	char *argnum;
	int argval;

/*	printf("into push\n");*/
	argnum = strtok(NULL, " \n\t\v\r\a");
	if (argnum == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: usage: push integer\n", line_num);
		exit(EXIT_FAILURE);
	}
/*	printf("past argnum strtok assignment\n");*/
	if (isnum(argnum) == 0)
	{
		dprintf(STDERR_FILENO, "L%d: usage: push integer\n", line_num);
		exit(EXIT_FAILURE);
	}
/*	printf("past isnum if\n");*/
	argval = atoi(argnum);
/*	printf("past atoi part: %d\n", argval);*/
	add_dnode_int_end(stack, argval);
/*	printf("past add dnode end\n");*/
}
/**
* add_dnode_int_end - adds node to end of list
* Return: void
* @head: the head node
* @n: number to be added
*/
void *add_dnode_int_end(stack_t **head, int n)
{
	stack_t *newtail, *temp;

/*	printf("into add dnode end\n");*/
	newtail = malloc(sizeof(stack_t));
	if (!newtail)
	{
		dprintf(STDERR_FILENO, "malloc failed\n");
		exit(EXIT_FAILURE);
	}
/*	printf("past newtail malloc\n");*/
	newtail->n = n;
	newtail->next = NULL;
	newtail->prev = NULL;
/*	printf("past newtail assignment\n");*/
	if (*head == NULL)
	{
/*		printf("into changing head\n");*/
		*head = newtail;
	}
	else
	{
		temp = *head;
		while (temp->next)
			temp = temp->next;
		temp->next = newtail;
		newtail->prev = temp;
	}
/*	printf("past head assignment/loop\n");*/
	return (newtail);
}

/**
* isnum - tests if a number is a digit
* Return: 1 if it is a number else 0
* @argnum: the string number
*/
int isnum(char *argnum)
{
	int len, i, sign = 0;

	len = strlen(argnum);
	for (i = 0; i < len; i++)
	{
		if (argnum[i] == '-' && sign == 1)
			return (0);
		else if (argnum[i] == '-')
			sign = 1;
		else if (isdigit(argnum[i]) == 0)
			return (0);
	}
	return (1);
}
