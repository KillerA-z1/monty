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

/**
 * rotr_func - rotates the stack to the right
 * @stack: pointer to the stack
 * @line_number: number of the line where the opcode occurs (unused)
 */
void rotr_func(stack_t **stack, unsigned int line_number)
{
	stack_t *last;
	(void)line_number;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	last = *stack;

	while (last->next != NULL)
		last = last->next;

	last->prev->next = NULL;
	last->prev = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
}

/**
 * stack_func - Sets the format of the data to a stack (LIFO)
 * @stack: Pointer to the top mode node of a stack_t linked list
 * @line_number: The current working line number of a Monty bytecodes file
 */
void stack_func(stack_t **stack, unsigned int line_number)
{
	if (stack && *stack)
		(*stack)->n = STACK;
	else
	{
		fprintf(stderr, "L%d: can't set stack, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * queue_func - Sets the format of the data to a queue (FIFO)
 * @stack: Pointer to the top mode node of a stack_t linked list
 * @line_number: The current working line number of a Monty bytecodes file
 */
void queue_func(stack_t **stack, unsigned int line_number)
{
	if (stack && *stack)
		(*stack)->n = QUEUE;
	else
	{
		fprintf(stderr, "L%d: can't set queue, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}
