#include "monty.h"
/**
 * main - the entry point
 * @argc: the argument counter
 * @argv: arguments
 * Return: 0
 */
int main(int argc, char *argv[])
{
	FILE *fd; /* create a file descriptor */
	char *buffer; /* line of the file */
	size_t buf_size = 0; /* the size of the buffer */
	ssize_t read; /* to read line per line */
	stack_t *stack = NULL; /*the top of the stack */
	char *opcodes; /* to strtok the line of the file*/
	unsigned int line_number = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		free(stack);
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r"); /* to open and to read the file bytecode*/
	if (fd == NULL) /* if it's not possible to open the file */
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		free(stack);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&buffer, &buf_size, fd)) != -1) /* read line/line */
	{
		opcodes = strtok(buffer, " \n\t"); /* to cut int the line */
		get_opcodes(&stack, opcodes, line_number);
		line_number++;
	}
	fclose(fd);
	free(buffer);
	free_all(&stack);
	return (0);
}
