#include "monty.h"
unsigned int value;
/**
 * get_opcodes - to select the good function.
 * @buffer: a line of the file.
 * @stack: the element at the top of the stack.
 * @line_number: the line traited.
 * Return: Always 0.
 */
void get_opcodes(stack_t **stack, char *buffer, unsigned int line_number)
{
	instruction_t op_list[] = {
		{"push", _push},
		{"pall", _pall},
		/*
		   {"pint", _pint},
		   {"pop", _pop},
		   {"swap", _swap},
		   {"add", _add},
		   {"nop", _nop},
		 */
		{NULL, NULL}
	};
	int i = 0;
	char *val;

	while (op_list[i].opcode != NULL)
	{
		if (strcmp(op_list[i].opcode, buffer) == 0)
		{
			val = strtok(NULL, " \n");
			if (val)
				value = atoi(val);
			op_list[i].f(stack, line_number);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%i: unknown instruction %s\n", line_number, op_list[i].opcode);
	exit(EXIT_FAILURE);

}
