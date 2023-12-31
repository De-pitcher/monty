#include "monty.h"

/**
 * pop_error - Prints pop error messages for empty stacks.
 *
 * @line_number: Line number in script where error occurred.
 *
 * Return: 1.
 */
int pop_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);

	return (EXIT_FAILURE);
}

/**
 * pint_error - Prints pint error messages for empty stacks.
 *
 * @line_number: Line number in script where error occurred.
 *
 * Return: 1.
 */
int pint_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);

	return (EXIT_FAILURE);
}

/**
 * stkque_error - Prints monty math function error messages
 *                     for stqueack//queues smaller than two nodes.
 *
 * @line_number: Line number in script where error occurred.
 * @op: Operations where error occurred.
 *
 * Return: 1.
 */
int stkque_error(unsigned int line_number, char *op)
{
	fprintf(stderr, "L%u: can't %s, stack too short\n", line_number, op);

	return (EXIT_FAILURE);
}

/**
 * div_error - Prints division error messages for division by 0.
 *
 * @line_number: Line number in script where error occurred.
 *
 * Return: 1.
 */
int div_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: division by zero\n", line_number);

	return (EXIT_FAILURE);
}

/**
 * pchar_error - Prints pchar error messages for empty stacks
 *               empty stacks and non-character values.
 *
 * @line_number: Line number in script where error occurred.
 * @message: The corresponding error message to print.
 *
 * Return: 1.
 */
int pchar_error(unsigned int line_number, char *message)
{
	fprintf(stderr, "L%u: can't pchar, %s\n", line_number, message);

	return (EXIT_FAILURE);
}
