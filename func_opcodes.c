#include "monty.h"
/**
 * _push - to add an item to the stack.
 * @stack: the element at the top of the stack.
 * @line_number: the line traited.
 */
void _push(stack_t **stack, unsigned int line_number)
{
	int n = 0;
	stack_t *new_stack;

	if(_isdigit(value) == 0)
	{
		fprintf(stderr, "L<%i>: usage: push integer", line_number);
		exit(EXIT_FAILURE);
	}

	n = value;
	new_stack = malloc(sizeof(stack_t));
	if (new_stack == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	new_stack->n = n; /* first element and the only one */
	new_stack->next = NULL;
	new_stack->prev = NULL;
	
	
	if(stack == NULL) /* if the stack is empty */
	{
		stack = &new_stack;
	}
	else
	{
		(*stack)->prev = new_stack;
		new_stack->next = *stack;  /* to push on the stack(elements of the stack are grouped */
	}
}


/**
 * _pall - to display all items of the stack.
 * @stack: the element at the top of the stack.
 * @line_number: the line traited.
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	int n = 0;
	int i = 0; /* to travel in all elements of the stack */
	stack_t *new_stack;
	(void)line_number;
	(void)*stack;

	new_stack = malloc(sizeof(stack_t));
	if (new_stack == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}        while (new_stack != NULL)
	{
		printf("%d\n", new_stack->n);
		i++;
		new_stack = new_stack->next;
	}
}
