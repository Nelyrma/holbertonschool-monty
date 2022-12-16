#include "monty.h"
int value;

/**
 * _pint - display the top of the stack
 * @stack: element at the top of the stack
 * @line_number: the line traited
 */
void _pint(stack_t **stack, unsigned int line_number)
{
        if (!stack || !*stack)
        {
                printf("L%i: can't pint, stack empty\n", line_number);
                exit(EXIT_FAILURE);
        }
        printf("%d\n", (*stack)->n);
}


/**
 * _swap - swap locations of previous stack with the top stack
 * @h: node to be swapped
 * @line_number: node number
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;


	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("L%i: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	temp = temp->next;
	if (temp->next != NULL)
	{
		(*stack)->next = temp->next;
		(*stack)->next->prev = *stack;
	}
	else
	{
		temp->prev->prev = temp;
		temp->prev->next = NULL;
	}
	temp->prev = NULL;
	temp->next = *stack;
	(*stack) = temp;
}


/**
 * _nop - do nothing
 * @h: head of list
 * @line_number: bytecode line number
 */
void _nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
