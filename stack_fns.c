#include "monty.h"

/**
 * free_stack - Frees a stack_t stack.
 *
 * @stack: A pointer to the top(stack) or bottom(queue) of list.
 */
void free_stack(stack_t **stack)
{
	stack_t *tmp = (*stack);

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

/**
 * init_stack - Initialize a stack_t stack with
 *              beginning stack and ending queue.
 *
 * @stack: A pointer to an unitialized stack_t stack.
 *
 * Return: If an error occurs - 1. Otherwise - 0.
 */
int init_stack(stack_t **stack)
{
	stack_t *start;

	start = malloc(sizeof(stack_t));

	if (start == NULL)
		return (malloc_error());

	start->n = STACK;
	start->prev = NULL;
	start->next = NULL;
	*stack = start;

	return (EXIT_SUCCESS);
}

/**
 * check_mode - Checks if a stack_t linked list is in stack or queue mode.
 *
 * @stack:A pointer to the top (stack) or
 *          bottom (queue) of a stack_t linked list as the case may be.
 *
 * Return: If the stack_t is in stack mode - STACK (0).
 *         If the stack_t is in queue mode - QUEUE (1).
 *         Otherwise - 2.
 */
int check_mode(stack_t *stack)
{
	if (stack->n == STACK)
		return (STACK);
	else if (stack->n == QUEUE)
		return (QUEUE);

	return (2);
}

/**
 * handle_check_mode - Completes the push after handling the check mode.
 *
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @tmp_s: A pointer to a temorary stack_t linked list.
 * @new_s: A pointer to a new stack_t linked list.
 */
void handle_check_mode(stack_t **stack, stack_t *tmp_s, stack_t *new_s)
{
	if (check_mode(*stack) == STACK)
	{
		tmp_s = (*stack)->next;
		new_s->prev = *stack;
		new_s->next = tmp_s;

		if (tmp_s)
			tmp_s->prev = new_s;
		(*stack)->next = new_s;
	}
	else
	{
		tmp_s = *stack;
		while (tmp_s->next)
			tmp_s = tmp_s->next;
		new_s->prev = tmp_s;
		new_s->next = NULL;
		tmp_s->next = new_s;
	}
}
