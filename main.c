#include "monty.h"

/**
* main - run the opcode file
* Return: 0 success or exit value
* @argc: the number of args
* @argv: array of string arguments
*/
int main(int argc, char *argv[])
{
	int line = 1, l;
	FILE *filenum;
	char *linebuf = NULL, *opcode;
	size_t n = 0;
	stack_t *head;
	void (*f)(stack_t **, unsigned int);

	head = NULL;
/*	opcode = malloc(sizeof(char *));*/
	printf("argv1: %s and argc%d\n",argv[1], argc); 
	if (argc != 2)
	{
		perror("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	printf("past first if in main\n");
	filenum = fopen(argv[1], "r+");
	printf("the file is %s", argv[0]);
	if (filenum == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (line > 0)
	{
		printf("line number: %d: %d\n", line, l);
		l = getline(&linebuf, &n, filenum) == -1;
		printf("---l is %d\n", l);
		if (l != -1 || l == 0)
		{
			opcode = strtok(linebuf, " \n\t\v\r\a");
			f = get_op(opcode);
			printf("past assigning function\n");
			if (!f)/* take away later maybe*/
				exit(EXIT_FAILURE);
			f(&head, line);
			printf("----. linebuf:%s> opcode:%s\n", linebuf, opcode);
/*			if (linebuf)
				free(linebuf);*/
			printf("past free in f section\n");
			line++;
		}
		else
		{
/*			free stack*/
/*			if (linebuf)*/
			free(linebuf);
			line = 0;
		}
	}
	return (0);
}
