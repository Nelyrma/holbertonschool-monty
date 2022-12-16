#include "monty.h"
/**
 * _isdigit - check for a digit
 * @str: pointer string
 * Return: 0 if c is a digit, 1 otherwize
 */
int _isdigit(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (!((str[i] >= '0' && str[i] <= '9') || (str[0] == '-')))
			return (1); /* false */
		i++;
	}
	return (0);
}


/**
 * free_all - to free all
 * @stack: double pointer to the top of the stack
 */
void free_all(stack_t **stack)
{
	stack_t *temp = NULL;

	while (*stack != NULL)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = NULL;
		*stack = temp;
	}
	free(*stack);
}
