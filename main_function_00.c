#include "monty.h"


/**
 * add_func - Adds the top two elements of the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number of the opcode being executed.
 */
void add_func(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	pop_func(stack, line_number);
}
