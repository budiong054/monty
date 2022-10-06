#include "monty.h"

/**
 * isempty - checks if a stack is empty or not
 * @stack: pointer to the top of the stack
 *
 * Return: 1 if it's empty, or 0 otherwise
 */

int isempty(stack_t *stack)
{
	if (stack)  /* if stack is not NULL */
		return (0);
	else
		return (1);
}

/**
 * err - print an error to stderr if opcode is not found
 * @stack: pointer to the top of the stack
 * @line_number: the line number
 *
 * Return: Nothing
 */

void err(__attribute__((unused)) stack_t **stack, unsigned int line_number)
{
	/* Error message */
	dprintf(STDERR_FILENO, "L%d: unknown instruction <opcode>\n", line_number);
	exit(EXIT_FAILURE);
}

/**
 * stack_len - return the number of element in the stack
 * @stack: pointer to the top of the stack
 *
 * Return: the number of element in the stack
 */

int stack_len(stack_t *stack)
{
	int len = 0;
	stack_t *temp;

	temp = stack;
	while (temp)
	{
		temp = temp->next;
		len++;
	}
	return (len);
}
