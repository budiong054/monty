#include "monty.h"

int num = 0;
/**
 * exec_opcode - execute the opcode instructions from the monty file
 * @stack: pointer to the top of the stack
 * @lineptr: pointer to the line red from the file
 * @line_number: the line number on the file
 *
 * Return: Nothing
 */

void exec_opcode(stack_t **stack, char *lineptr, unsigned int line_number)
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
		num = atoi(token);

	(get_opcode_func(opcode))(stack, line_number);
}

/**
 * get_opcode_func - get the opcode function corresponding to the
 * opcode instruction
 * @opcode: the opcode instruction
 *
 * Return: Nothing
 */

void (*get_opcode_func(char *opcode))(stack_t **, unsigned int)
{
	unsigned int i;
	unsigned int len;
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"err", err}
	};

	len = sizeof(instructions) / sizeof(instructions[0]);
	for (i = 0; i < len - 1; i++)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			return (instructions[i].f);
		}
	}
	return (instructions[i].f);
}
