#include "monty.h"

/**
* get_op - gets the function from possible functions
* Return: void
* @op_code: the char * code for the bytecode
*/
void (*get_op(char *op_code))(stack_t **stack, unsigned int line_number)
{
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"nop", NULL},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{NULL, failure},
		{NULL, NULL}
	};
	int i = 0;

	if (op_code == NULL)
		return (NULL);
	while (i < 6)
	{
/*		printf("in the while in get_op\n");*/
		if (strcmp(((ops + i))->opcode, op_code) == 0)
		{
/*			printf("in the if in getop\n");*/
			return ((ops + i)->f);
		}
		i++;
	}
/*
*	fprintf(STDERR_FILENO, "L%i: unknown instruction %s\n",
*			 line_number, opcode);
*	FREE stack
*/
	return ((ops + 6)->f);
}
/**
* failure - no function found
* Return: void
* @stack: the head node of the stack
* @line_num: the line num
*/
void failure(stack_t **stack, unsigned int line_num)
{
	(void) line_num;
	free_stack_t(stack);

	dprintf(STDERR_FILENO, "L%i: unknown instruction\n",
		line_num);
	exit(EXIT_FAILURE);
}
