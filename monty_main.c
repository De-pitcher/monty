#include "monty.h"

/* char **op_toks = NULL;*/

/**
 * main - The entry point for monty Interpretor.
 *
 * @argc: The counter of arguments.
 * @argv: Pointer to an array of char pointers to argumnents.
 *
 * Return: 0 on success, 1 on error.
 */
int main(int argc, char **argv)
{
	FILE *script_fd = NULL;
	int status = EXIT_SUCCESS;

	if (argc != 2)
		return (usage_error());
	script_fd = fopen(argv[1], "r");

	if (script_fd == NULL)
		return (fopen_error(argv[1]));
	status = exe_monty(script_fd);
	fclose(script_fd);

	return (status);
}