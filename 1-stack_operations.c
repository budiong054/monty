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
	stack_t *new_stack; 

	new_stack = malloc(sizeof(stack_t)); 


	if (new_stack == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	
	if (!num)
	{
		dprintf(STDERR_FILENO, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_stack->n = num; 
	new_stack->prev = NULL; 
	new_stack->next = (*stack); 
	*stack = new_stack;
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
	stack_t *temp; 

	temp = *stack; 

	
	if (isempty(*stack))
		return;

	
	while (temp)
	{
		printf("%d\n", temp->n); 
		temp = temp->next; 
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
	if (isempty(*stack))
	{
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n); 
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
	stack_t *temp; 


	if (isempty(*stack))
	{
		dprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	
	temp = *stack;
	num = temp->n;
	*stack = temp->next;
	if (temp->next)
		(*stack)->prev = temp->prev;
	free(temp); 
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
