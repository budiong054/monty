#include "../monty.h"

stack_t *top = NULL;
/**
 * main - check the code
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
	stack_t *new;
	stack_t hello = {8, NULL, NULL};
	int n;

	top = &hello;
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		dprintf(2, "Error: can't malloc\n");
		return (EXIT_FAILURE);
	}
	new->n = 9;
	top->prev = new;
	new->next = top;
	new->prev = NULL;
	top = new;

	if (isempty())
		printf("Stack is empty\n");
	else
	{
		n = pall();
		printf("%d -> element\n", n);
	}

	free(new);
	top = NULL;

	return (EXIT_SUCCESS);
}
