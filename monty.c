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
	char *fileS;
	char **lines;
	char *fileName;

	/* fileName = "bytecodes/test.m"; */
	fileName = argv[1];
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	info.stack_head = head;
	info.stack_size = 0;
	info.line = 1;

	fileS = sReadFile(fileName);
	lines = parse_to_lines(fileS);
	info.tokens = NULL;

	while (lines[info.line - 1] != NULL)
	{
		if (strlen(lines[info.line - 1]) != 0 && lines[info.line - 1][0] != '#' && !is_whitespace(lines[info.line - 1]))
		{
			new_op_handler(&info, lines[info.line - 1]);
		}
		info.line++;
	}
	/* freeing last command */
	free(info.tokens);

	free(fileS);
	free(lines);
	pop_all_stack_s(&info);

	return (0);
}
