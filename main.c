#include "monty.h"
/**
 * read_file - reads a bytecode file and runs commands
 * @filename: pathname to file
 * @stack: pointer to the top of the stack
 */
void read_file(char *filename, stack_t **stack)
{
	FILE *file;
	char *line = NULL;
	size_t line_size = 0;
	int line_count = 1;
	instruct_func opcode_func;
	int read;

	file = fopen(filename, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&line, &line_size, file)) != -1)
	{
		char *opcode = parse_line(line, stack, line_count);

		if (opcode == NULL || opcode[0] == '#')
		{
			line_count++;
			continue;
		}

		opcode_func = get_op_func(opcode);
		if (opcode_func == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_count, opcode);
			exit(EXIT_FAILURE);
		}

		opcode_func(stack, line_count);
		line_count++;
	}

	free(line);
	if (fclose(file) == EOF)
		exit(EXIT_FAILURE);
}
