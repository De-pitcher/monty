#include "monty.h"

/**
 * monty_push - Pushes a value to a stack_t linked list.
 *
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @op_toks: OP tokens.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void monty_push(stack_t **stack, char **op_toks, unsigned int line_number)
{
	stack_t *tmp, *new;
	int index;

	new = malloc(sizeof(stack_t));
	tmp = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		set_op_tok_error(op_toks, malloc_error());
		return;
	}

	if (op_toks[1] == NULL)
	{
		set_op_tok_error(op_toks, (line_number));
		return;
	}

	for (index = 0; op_toks[1][index]; index++)
	{
		if (op_toks[1][index] == '-' && index == 0)
			continue;
		if (op_toks[1][index] < '0' || op_toks[1][index] > '9')
		{
			set_op_tok_error(op_toks, (line_number));
			return;
		}
	}
	new->n = atoi(op_toks[1]);

	handle_check_mode(stack, tmp, new);
}

/**
 * monty_pall - Prints the value of a stack_t linked list.
 *
 * @stack: A pointer to the top mode node of the list.
 * @op_toks: OP tokens.
 * @line_number: The current working line number of a monty bytecode file.
 */
void monty_pall(stack_t **stack, char **op_toks, unsigned int line_number)
{
	stack_t *tmp = (*stack)->next;
	(void)op_toks;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
	(void)line_number;
}

/**
 * monty_pint - Prints the top value of a stack_t list.
 *
 * @stack: A pointer to the top mode node of the list.
 * @op_toks: OP tokens.
 * @line_number: The current working line number of a monty bytecode file.
 */
void monty_pint(stack_t **stack, char **op_toks, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		set_op_tok_error(op_toks, pint_error(line_number));

		return;
	}
	printf("%d\n", (*stack)->next->n);
}

/**
 * monty_pop - Removes the top value element of a stack list.
 *
 * @stack: A pointer to the top mode node of the list.
 * @op_toks: OP tokens.
 * @line_number: The current working line number of a monty bytecode file.
 */
void monty_pop(stack_t **stack, char **op_toks, unsigned int line_number)
{
	stack_t *next = NULL;

	if ((*stack)->next == NULL)
	{
		set_op_tok_error(op_toks, pop_error(line_number));

		return;
	}

	next = (*stack)->next->next;
	free((*stack)->next);

	if (next)
		next->prev = *stack;
	(*stack)->next = next;
}

/**
 * monty_swap - Swap the top two value elements of a stack list.
 *
 * @stack: A pointer to the top mode node of the list.
 * @op_toks: OP tokens.
 * @line_number: The current working line number of a monty bytecode file.
 */
void monty_swap(stack_t **stack, char **op_toks, unsigned int line_number)
{
	stack_t *tmp;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(op_toks, stkque_error(line_number, "swap"));

		return;
	}
	tmp = (*stack)->next->next;
	(*stack)->next->next = tmp->next;
	(*stack)->next->prev = tmp;

	if (tmp->next)
		tmp->next->prev = (*stack)->next;
	tmp->next = (*stack)->next;
	tmp->prev = *stack;
	(*stack)->next = tmp;
}
