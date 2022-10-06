#include "monty.h"


/**
 * main - Monty program entry point
 * @argc: Number of argument passed to the program
 * @argv: Pointer to the argument passed
 *
 * Return: 0 on success or a non-zero otherwise
 */

int main(int argc, char *argv[])
{
	stack_t *stack = NULL; /* pointer to the top of the stack */
	char *filename; /* pointer to the filename */
	FILE *stream;	/* pointer to the file stream */
	char *lineptr = NULL;
	size_t n = 0;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	filename = argv[1];
	stream = fopen(filename, "r");
	if (!stream)
	{
		dprintf(STDERR_FILENO, "Error: Can't open %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while (getline(&lineptr, &n, stream) != -1)
	{
		line_number++;
		exec_opcode(&stack, lineptr, line_number);
	}
	free(lineptr);
	fclose(stream);
	return (0);
}
