#include "monty.h"

const instruction_t opcodes[] = {
	{"push", push_op},
	{"pall", pall_op},
	{NULL, NULL}};

/**
 * push_op - push a new node to the stack
 * @info: pointer to the monty info struct
 * @arg: argument to be pushed
 */
void push_op(monty_info_t *info)
{
	char *arg;
	int new_num;

	if (info == NULL)
		return;
	if (info->token_index + 1 >= info->tokens_len)
	{
		fprintf(stderr, "L%d: usage: push integer\n", info->line);
		return;
	}
	arg = info->tokens[info->token_index + 1];
	new_num = 0;

	if (arg == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", info->line);
		return;
	}
	new_num = atoi(arg);
	if (push_stack_s(info, new_num) == 1)
		return;
	info->token_index++;
}

/**
 * pall_op - print the stack
 * @info: pointer to the monty info struct
 * @arg: argument to be pushed
 */
void pall_op(monty_info_t *info)
{
	print_stack_s(info->stack_head);
}

/**
 * get_op_func - get the opcode function
 * @s: opcode
 * Return: pointer to the opcode function
 */
void (*get_op_func(char *s))(monty_info_t *info)
{
	int i = 0;

	while (opcodes[i].opcode != NULL)
	{
		if (strcmp(opcodes[i].opcode, s) == 0)
			return (opcodes[i].f);
		i++;
	}
	return (NULL);
}

/**
 * op_handler - handles the operations
 * @info: pointer to the monty info struct
 * @tokens: array of tokens
 * Return: 0 on success, 1 on failure
 */
int op_handler(monty_info_t *info)
{
	/*
	print_tokens(info->tokens);
	printf("-------------------------------------------------\n");
	*/
	void (*op_func)(monty_info_t *info);

	info->token_index = 0;

	while (info->tokens[info->token_index] != NULL)
	{
		op_func = get_op_func(info->tokens[info->token_index]);
		if (op_func == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", info->line, info->tokens[info->token_index]);
			return (1);
		}
		op_func(info);
		info->token_index++;
		info->line++;
	}
	return (0);
}