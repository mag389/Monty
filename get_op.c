#include "monty.h"

/**
* get_op - gets the function from possible functions
* Return: void
* @opcode: the char * code for the bytecode
*/
void (*get_op(char *op_code))(stack_t **stack, unsigned int line_number)
{
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};
	int i = 0;

	if (op_code == NULL)
		return (NULL);
	while (i < 2)
	{
		printf("in the while in get_op\n");
		if (strcmp(((ops + i))->opcode, op_code) == 0)
		{
			printf("in the if in getop\n");
			return ((ops + i)->f);
		}
		i++;
	}
/*	fprintf(STDERR_FILENO, "L%i: unknown instruction %s\n",
			 line_number, opcode);
	FREE stack */
	return (NULL);
/*	exit(EXIT_FAILURE); uncomment later, doing this for testing now*/
}
