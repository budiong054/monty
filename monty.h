#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* global variable */
extern int num;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* 1 - stack operations */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);

/* 2- stack operations file */
void add(stack_t **add, unsigned int line_number);
void nop(stack_t **add, unsigned int line_number);

/* exec_opcode file  */
void exec_opcode(stack_t **stack, char *lineptr, unsigned int line_number);
void (*get_opcode_func(char *opcode))(stack_t **, unsigned int);

/* stack_utils functions */
int isempty(stack_t *stack);
void err(stack_t **stack, unsigned int line_number);
int stack_len(stack_t *stack);

#endif /* MONTY_H */
