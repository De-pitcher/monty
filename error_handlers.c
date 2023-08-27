#include "monty.h"

/**
 * usage_error - Prints usage error messages.
 *
 * Return: EXIT_FAILURE (Always).
 */
int usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");

	return (EXIT_FAILURE);
}

/**
 * malloc_error - Prints malloc error messages.
 *
 * Return: 1.
 */
int malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");

	return (EXIT_FAILURE);
}

/**
 * fopen_error - Prints error messages   for file opening with file name.
 *
 * @filename: Name of file failed to open.
 *
 * Return: 1.
 */
int fopen_error(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);

	return (EXIT_FAILURE);
}

/**
 * unknown_op_error - Handles unknown instruction error.
 *
 * @opcode: Opcode where error occurred.
 * @line_number: Line number in monty bytecodes file where error occured.
 *
 * Return: 1.
 */
int unknown_op_error(char *opcode, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);

	return (EXIT_FAILURE);
}

/**
 * invalid_arg_error - Prints invalid monty_push argument error messages.
 *
 * @line_number: Line number in monty bytecodes file where error occurred.
 *
 * Return: 1.
 */
int invalid_arg_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_number);

	return (EXIT_FAILURE);
}