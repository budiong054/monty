#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: pointer to the pointer to the top of the stack
 * @line_number: the line number
 *
 * Return: Nothing
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_stack; /* declare a new element to be push to the stack */

	new_stack = malloc(sizeof(stack_t)); /* allocate memory space for it */

	/* check if the memory allocation was successful or not */
	if (new_stack == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	/* check whether the user inputed an integer value or not */
	if (!num)
	{
		dprintf(STDERR_FILENO, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_stack->n = num; /* assign the n part to the integer */
	new_stack->prev = NULL; /* set the previous to NULL */
	new_stack->next = (*stack); /* set the new element to the top */
	*stack = new_stack; /* assign address of new element to top ptr */
}


/**
 * pall - prints all the value on the stack, starting from the top
 * of the stack
 * @stack: pointer to the pointer to the top of the stack
 * @line_number: the line number
 *
 * Return: Nothing
 */

void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *temp; /* declare a temporary pointer */

	temp = *stack; /* assign the address of the top pointer */

	/* check if the stack if empty */
	if (isempty(*stack))
		return;

	/* Traverse through the stack from top to bottom */
	while (temp)
	{
		printf("%d\n", temp->n); /* print the value */
		temp = temp->next; /* move to the next element on the stack */
	}
}


/**
 * pint - prints the value at the top of the stack,
 * followed by a new line
 * @stack: pointer to the pointer to the top of the stack
 * @line_number: the line number
 *
 * Return: Nothing
 */

void pint(stack_t **stack, unsigned int line_number)
{
	/* check if the stack is empty or not */
	if (isempty(*stack))
	{
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n); /* print the value at the top */
}


/**
 * pop - removes the top element of the stack
 * @stack: pointer to the pointer to the top of the stack
 * @line_number: the line number
 *
 * Return: Nothing
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp; /* declare a temporary pointer */

	/* check if the stack is empty or not */
	if (isempty(*stack))
	{
		dprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* delete the top element from the stack */
	temp = *stack;
	num = temp->n;
	*stack = temp->next;
	if (temp->next)
		(*stack)->prev = temp->prev;
	free(temp); /* free the memory allocated for the element */
}

/**
 * swap - swaps the top two elements of the stack
 * @stack: pointer to the top of the stack
 * @line_number: the line number
 *
 * Return: Nothing
 */

void swap(stack_t **stack, unsigned int line_number)
{
	int top_1, top_2, len;

	len = stack_len(*stack);
	if (len < 2)
	{
		dprintf(STDERR_FILENO, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	pop(stack, line_number);
	top_1 = num;
	pop(stack, line_number);
	top_2 = num;

	num = top_1;
	push(stack, line_number);

	num = top_2;
	push(stack, line_number);
}
