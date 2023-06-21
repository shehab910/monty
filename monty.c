#include "monty.h"

int main(void)
{
	monty_info_t info;
	stack_t *head = NULL;

	info.stack_head = head;
	info.stack_size = 0;
	info.line = 1;

	char *fileS = sReadFile("bytecodes/custom_1.m");
	char **tokens = parse(fileS);

	info.tokens = tokens;

	int i = 0;
	while (tokens[i] != NULL)
		i++;
	info.tokens_len = i;
	info.token_index = 0;

	return (op_handler(&info));
	return (0);
}