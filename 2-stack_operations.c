#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @stack: pointer to the top of the stack
 * @line_number: the line_number
 *
 * Return: Nothing
 */

void add(stack_t **stack, unsigned int line_number)
{
	int top_1, top_2, len;

	len = stack_len(*stack);
	if (len < 2)
	{
		dprintf(STDERR_FILENO, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	pop(stack, line_number);
	top_1 = num;

	pop(stack, line_number);
	top_2 = num;

	num = top_1 + top_2;
	push(stack, line_number);
}

/**
 * nop - doesn't do anything
 * @stack: pointer to the top of the stack
 * @line_number: the line number
 *
 * Return: nothing
 */

void nop(__attribute__((unused)) stack_t **stack,
		__attribute__((unused)) unsigned int line_number)
{
}
