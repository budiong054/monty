#include "monty.h"

/**
 * exec_opcode - execute the opcode instructions from the monty file
 * @stack: pointer to the top of the stack
 * @lineptr: pointer to the line red from the file
 * @line_number: the line number on the file
 *
 * Return: Nothing
 */

void exec_opcode(__attribute__((unused)) stack_t **stack, char *lineptr, unsigned int line_number)
{
	int i;
	char *token;
	char *opcode;

	token = strtok(lineptr, " ,\n");
	for (i = 0; i < 1 && token; i++)
	{
		opcode = token;
		token = strtok(NULL, " ");
	}

	if (strcmp(opcode, "push") == 0)
	{
		n = atoi(token);
		printf("[%d] -> %s %d\n", line_number, opcode, n);
	}
	else
		printf("[%d] -> %s\n", line_number, opcode);
}
