#include "../monty.h"

stack_t *top = NULL;
/**
 * main - check the code
 *
 * Return: Always EXIT_SUCCESS
 */
int main(void)
{
	stack_t *new;
	stack_t hello = {8, NULL, NULL};

	if (isempty())
		printf("The stack is empty\n");
	else
		printf("The stack is not empty\n");

	top = &hello;
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		dprintf(2, "Error: Can't malloc\n");
		return (EXIT_FAILURE);
	}
	new->n = 9;
	top->prev = new;
	new->next = top;
	new->prev = NULL;
	top = new;

	if (isempty())
		printf("The stack is empty\n");
	else
		printf("The stack is not empty\n");

	free(new);
	top = NULL;

	if (isempty())
		printf("The stack is empty\n");
	else
		printf("The stack is not empty\n");
	return (EXIT_SUCCESS);
}
