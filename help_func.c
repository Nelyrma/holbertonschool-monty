#include "monty.h"
/**
 * _isdigit - check for a digit
 * @c: the character to check
 * Return: 1 if c is a digit, 0 otherwize
 */
int _isdigit(char *str)
{
	int i = 0;
	while(str[i])
	{	
		if (!((str[i] >= '0' && str[i] <= '9') || (str[0] == '-')))
			return (1); /* false */
		i++;
	}
	return (0);
}
