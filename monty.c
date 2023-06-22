#include "monty.h"

/**
 * main - entry point
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char **argv)
{
	monty_info_t info;
	stack_t *head = NULL;
	char *fileName;

	/* fileName = "bytecodes/task0/task0_1.m"; */
	fileName = argv[1];
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	info.stack_head = head;
	info.stack_size = 0;
	info.line = 1;

	info.fileS = sReadFile(fileName);
	info.lines = parse_to_lines(info.fileS);
	info.tokens = NULL;
	info.dup = NULL;

	while (info.lines[info.line - 1] != NULL)
	{
		if (
			strlen(info.lines[info.line - 1]) != 0 &&
			info.lines[info.line - 1][0] != '#' &&
			!is_whitespace(info.lines[info.line - 1]))
		{
			op_handler(&info, info.lines[info.line - 1]);
		}
		info.line++;
	}
	/* freeing last command */
	free(info.tokens);
	info.tokens = NULL;

	grace_exit(&info, EXIT_SUCCESS);

	return (0);
}
