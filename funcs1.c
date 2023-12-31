#include "monty.h"

/**
 * monty_add - Adds the top two values of a stack list.
 *
 * @stack: A pointer to the top mode node of a stack list.
 * @op_toks: OP tokens.
 * @line_number: The current working line number of a monty bytecode file,
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value  is removed.
 */
void monty_add(stack_t **stack, char **op_toks, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(op_toks, stkque_error(line_number, "add"));

		return;
	}
	(*stack)->next->next->n += (*stack)->next->n;
	monty_pop(stack, op_toks, line_number);
}

/**
 * monty_sub - Substracts the second value from the top of
 *             a stack list by the top value.
 *
 * @stack: A pointer to the top mode node of a stack list.
 * @op_toks: OP tokens
 * @line_number: The current working line number of a monty bytecode file,
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value  is removed.
 */
void monty_sub(stack_t **stack, char **op_toks, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(op_toks, stkque_error(line_number, "sub"));

		return;
	}
	(*stack)->next->next->n -= (*stack)->next->n;
	monty_pop(stack, op_toks, line_number);
}

/**
 * monty_div - Divides the second value from the top of
 *             a stack list by the top value.
 *
 * @stack: A pointer to the top mode node of a stack list.
 * @op_toks: OP tokens.
 * @line_number: The current working line number of a monty bytecode file,
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value  is removed.
 */
void monty_div(stack_t **stack, char **op_toks, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(op_toks, stkque_error(line_number, "div"));

		return;
	}

	if ((*stack)->next->n == 0)
	{
		set_op_tok_error(op_toks, div_error(line_number));

		return;
	}
	(*stack)->next->next->n /= (*stack)->next->n;
	monty_pop(stack, op_toks, line_number);
}

/**
 * monty_mul - Multiplies the second value from the top of
 *             a stack list by the top value.
 *
 * @stack: A pointer to the top mode node of a stack list.
 * @op_toks: OP tokens.
 * @line_number: The current working line number of a monty bytecode file,
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value  is removed.
 */
void monty_mul(stack_t **stack, char **op_toks, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(op_toks, stkque_error(line_number, "mul"));

		return;
	}
	(*stack)->next->next->n *= (*stack)->next->n;
	monty_pop(stack, op_toks, line_number);
}

/**
 * monty_mod - Computes the modules of the second value from the top of
 *             a stack list by the top value.
 *
 * @stack: A pointer to the top mode node of a stack list.
 * @op_toks: OP tokens.
 * @line_number: The current working line number of a monty bytecode file,
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value  is removed.
 */
void monty_mod(stack_t **stack, char **op_toks, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(op_toks, stkque_error(line_number, "mod"));

		return;
	}

	if ((*stack)->next->n == 0)
	{
		set_op_tok_error(op_toks, div_error(line_number));

		return;
	}
	(*stack)->next->next->n %= (*stack)->next->n;

	monty_pop(stack, op_toks, line_number);
}

