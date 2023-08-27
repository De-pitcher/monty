#define _GNU_SOURCE
#include "monty.h"

int is_empty_line(char *line, char *delims);
void (*get_op_func(char *opcode))(stack_t**, char **, unsigned int);
int exe_monty(FILE *script_fd);

/**
 * free_tokens - Frees the global op_toks array of strings.
 * @op_toks: OP tokens
 */
void free_tokens(char **op_toks)
{
	size_t i = 0;

	if (op_toks == NULL)
		return;

	for (i = 0; op_toks[i]; i++)
		free(op_toks[i]);

	free(op_toks);
}

/**
 * tok_len - Gets the length of current op_toks.
 * @op_toks: OP tokens
 *
 * Return: Length of current op_toks (as int).
 */
unsigned int tok_len(char **op_toks)
{
	unsigned int toks_len = 0;

	while (op_toks[toks_len])
		toks_len++;
	return (toks_len);
}

/**
 * is_empty_line - Checks if a line read from getline only contains delimiters.
 * @line: A pointer to the line.
 * @delims: A string of delimiter characters.
 *
 * Return: If the line only contains delimiters - 1.
 *         Otherwise - 0.
 */
int is_empty_line(char *line, char *delims)
{
	int i, j;

	for (i = 0; line[i]; i++)
	{
		for (j = 0; delims[j]; j++)
		{
			if (line[i] == delims[j])
				break;
		}
		if (delims[j] == '\0')
			return (0);
	}

	return (1);
}

/**
 * get_op_func - Matches an opcode with its corresponding function.
 * @opcode: The opcode to match.
 *
 * Return: A pointer to the corresponding function.
 */
void (*get_op_func(char *opcode))(stack_t**, char **, unsigned int)
{
	instruction_t op_funcs[] = {
		{"push", monty_push},
		{"pall", monty_pall},
		{"pint", monty_pint},
		{"pop", monty_pop},
		{"swap", monty_swap},
		{"add", monty_add},
		{"nop", monty_nop},
		{"sub", monty_sub},
		{"div", monty_div},
		{"mul", monty_mul},
		{"mod", monty_mod},
		{"pchar", monty_pchar},
		{"pstr", monty_pstr},
		{"rotl", monty_rotl},
		{"rotr", monty_rotr},
		{"stack", monty_stack},
		{"queue", monty_queue},
		{NULL, NULL}
	};
	int i;

	for (i = 0; op_funcs[i].opcode; i++)
	{
		if (strcmp(opcode, op_funcs[i].opcode) == 0)
			return (op_funcs[i].f);
	}

	return (NULL);
}

/**
 * exe_monty - Executes a Monty bytecodes script.
 * @script_fd: File descriptor for an open Monty bytecodes script.
 *
 * Return: 0 on success, respective error code on failure.
 */
int exe_monty(FILE *script_fd)
{
	stack_t *stack = NULL;
	char *line = NULL, **op_toks = NULL;
	size_t len = 0, status = EXIT_SUCCESS;
	unsigned int line_number = 0, prev_tok_len = 0;
	void (*op_func)(stack_t**, char **, unsigned int);

	if (init_stack(&stack) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	while (getline(&line, &len, script_fd) != -1)
	{
		line_number++;
		op_toks = strtow(line, DELIMS);
		if (op_toks == NULL)
		{
			if (is_empty_line(line, DELIMS))
				continue;
			free_stack(&stack);
			return (malloc_error());
		}
		else if (op_toks[0][0] == '#')
		{
			free_tokens(op_toks);
			continue;
		}
		op_func = get_op_func(op_toks[0]);
		if (op_func == NULL)
		{
			free_stack(&stack);
			status = unknown_op_error(op_toks[0], line_number);
			free_tokens(op_toks);
			break;
		}
		prev_tok_len = tok_len(op_toks);
		op_func(&stack, op_toks, line_number);
		if (tok_len(op_toks) != prev_tok_len)
		{
			if (op_toks && op_toks[prev_tok_len])
				status = atoi(op_toks[prev_tok_len]);
			else
				status = EXIT_FAILURE;
			free_tokens(op_toks);
			break;
		}
		free_tokens(op_toks);
	}
	free_stack(&stack);

	if (line && *line == 0)
	{
		free(line);
		return (malloc_error());
	}

	free(line);
	return (status);
}
