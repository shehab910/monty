#include "monty.h"

int main(int argc, char **argv)
{
	monty_info_t info;
	stack_t *head = NULL;
	char *fileS;
	char **tokens;
	int i;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	info.stack_head = head;
	info.stack_size = 0;
	info.line = 1;

	fileS = sReadFile(argv[1]);
	tokens = parse(fileS);

	info.tokens = tokens;

	i = 0;
	while (tokens[i] != NULL)
		i++;
	info.tokens_len = i;
	info.token_index = 0;

	return (op_handler(&info));
	return (0);
}