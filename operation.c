#include "monty.h"

/**
 *sub_func - subtracts the top of the stack from the second top of the stack
 * @stack: pointer to the stack
 * @line_number: line number where the opcode occurs
 */
void sub_func(stack_t **stack, unsigned int line_number)
{
	int sub;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	sub = (*stack)->next->n - (*stack)->n;

	pop_func(stack, line_number);

	(*stack)->n = sub;
}

/**
 * _mul - multiplies the top of the stack by the second top of the stack
 * @stack: pointer to the stack
 * @line_number: line number where the opcode occurs
 */
void mul_func(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n *= (*stack)->n;
	pop_func(stack, line_number);
}