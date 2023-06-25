#include "monty.h"

/**
 * pchar_func - prints the ascii at the top of the stack
 * @stack: pointer to the stack
 * @line_number: number of the line where the opcode occurs (unused)
 */
void pchar_func(stack_t **stack, unsigned int line_number)
{
	int ascii;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	ascii = (*stack)->n;
	if (!isascii(ascii))
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	putchar(ascii);
	putchar('\n');
}
/**
 * rotl_func- rotates the stack to the left
 * @stack: pointer to the stack
 * @line_number: number of the line where the opcode occurs (unused)
 */
void rotl_func(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *current;
	(void)line_number;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	first = *stack;
	*stack = first->next;
	current = *stack;

	while (current->next != NULL)
		current = current->next;

	current->next = first;
	first->prev = current;
	first->next = NULL;
}

/**
 * pstr_func - prints the string contained in the stack
 * @stack: pointer to the stack
 * @line_number: number of the line where the opcode occurs (unused)
 */
void pstr_func(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	(void)line_number;

	tmp = *stack;

	while (tmp != NULL && tmp->n != 0 && isascii(tmp->n) && isprint(tmp->n))
	{
		putchar(tmp->n);
		tmp = tmp->next;
	}

	putchar('\n');
}
