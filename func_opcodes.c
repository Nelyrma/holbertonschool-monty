#include "monty.h"
/**
 * _push - to add an item to the stack.
 * @stack: the element at the top of the stack.
 * @line_number: the line traited.
 */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_stack;

	if(_isdigit(value) == 0)
	{
		fprintf(stderr, "L%i: usage: push integer", line_number);
		exit(EXIT_FAILURE);
	}

	new_stack = malloc(sizeof(stack_t));
	if (new_stack == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	new_stack->n = value; /* first element and the only one */
	new_stack->next = NULL;
	new_stack->prev = NULL;


	if(*stack != NULL) /* if the stack is empty */
	{
		(*stack)->prev = new_stack;
		new_stack->next = *stack;  /* to push on the stack(elements of the stack are grouped */
	}
	(*stack) = new_stack;
}


/**
 * _pall - to display all items of the stack.
 * @stack: the element at the top of the stack.
 * @line_number: the line traited.
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void)line_number;

	if (stack == NULL)
		exit(EXIT_FAILURE);

	temp = *stack;

	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
