#include "monty.h"
/**
 * free_dlistint - Frees a doubly linked list.
 * @head: Pointer to the head of the list.
 */
void free_dlistint(stack_t *head)
{
	stack_t *tmp;

	for (; head != NULL; head = tmp)
	{
		tmp = head->next;
		free(head);
	}
}

/**
 * _isalpha - checks if int is in alphabet
 * @c: int
 * Return: 1 if yes, 0 if no
 */
int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}
/**
 * isnumber - checks if a string is a number
 * @str: string being passed
 *
 * Return: 1 if the string is a number, 0 otherwise
 */
int isnumber(char *str)
{
	unsigned int i = 0;

	if (str == NULL || *str == '\0')
		return (0);

	if (str[i] == '-')
		i++;

	for (; str[i] != '\0'; i++)
	{
		if (!isdigit(str[i]))
			return (0);
	}

	return (1);
}

/**
 * parse_line - parses a line for an opcode and arguments
 * @line: the line to be parsed
 * @stack: pointer to the head of the stack
 * @line_number: the current line number
 * Return: returns the opcode or null on failure
 */
char *parse_line(char *line, stack_t **stack, unsigned int line_number)
{
	char *opcode, *push_str, *argument;
	(void)stack; /* Marking the parameter as unused */

	push_str = "push";
	opcode = strtok(line, " \t\n");
	if (opcode == NULL)
		return (NULL);

	if (strcmp(opcode, push_str) == 0)
	{
		argument = strtok(NULL, " \t\n");
		if (argument != NULL && isnumber(argument))
		{
			var_global.push_arg = atoi(argument);
		}
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}

	return (opcode);
}
