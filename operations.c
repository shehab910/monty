#include "monty.h"

const instruction_t opcodes[] = {
	{"push", push_op},
	{"pall", pall_op},
	{"pint", pint_op},
	{NULL, NULL}};

/**
 * push_op - push a new node to the stack
 * @info: pointer to the monty info struct
 */
void push_op(monty_info_t *info)
{
	char *arg;
	int new_num;

	if (info == NULL)
		exit(EXIT_FAILURE);
	if (info->tokens_len < 2)
	{
		fprintf(stderr, "L%d: usage: push integer\n", info->line);
		exit(EXIT_FAILURE);
	}
	arg = info->tokens[1];
	new_num = 0;

	if (arg == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", info->line);
		exit(EXIT_FAILURE);
	}
	if (is_number(arg) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", info->line);
		exit(EXIT_FAILURE);
	}
	new_num = atoi(arg);
	if (push_stack_s(info, new_num) == 1)
		exit(EXIT_FAILURE);
	info->token_index++;
}

/**
 * pall_op - print the stack
 * @info: pointer to the monty info struct
 */
void pall_op(monty_info_t *info)
{
	print_stack_s(info->stack_head);
}

/**
 * pint_op - print the top of the stack
 * @info: pointer to the monty info struct
 */
void pint_op(monty_info_t *info)
{
	stack_t *head = info->stack_head;

	if (head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", info->line);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", head->n);
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

instruction_t get_instruction(char *opcode)
{
	int i = 0;

	while (opcodes[i].opcode != NULL)
	{
		if (strcmp(opcodes[i].opcode, opcode) == 0)
			return (opcodes[i]);
		i++;
	}
	return (opcodes[i]);
}

/**
 * new_op_handler - executes one opcode (one line)
 * @info: pointer to the monty info struct
 * Return: 0 on success, 1 on failure
 */
int new_op_handler(monty_info_t *info, char *line)
{
	instruction_t instruction;
	char **tokens;
	char *dupline;

	dupline = _strdup(line);

	tokens = parse_line(dupline);

	if (tokens == NULL)
		return (1);

	instruction = get_instruction(tokens[0]);

	if (instruction.opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", 1, tokens[0]);
		exit(EXIT_FAILURE);
	}

	if (info->tokens != NULL)
	{
		free(info->tokens);
		info->tokens = NULL;
		info->tokens_len = 0;
	}
	info->tokens = tokens;
	info->tokens_len = arr2dlen(tokens);
	instruction.f(info);
	free(dupline);
	return (0);
}

/**
 * op_handler - handles the operations
 * @info: pointer to the monty info struct
 * Return: 0 on success, 1 on failure
 */
int op_handler(monty_info_t *info)
{
	/*
	 * print_tokens(info->tokens);
	 * printf("-------------------------------------------------\n");
	 */
	void (*op_func)(monty_info_t *info);

	info->token_index = 0;

	while (info->tokens[info->token_index] != NULL)
	{
		op_func = get_op_func(info->tokens[info->token_index]);
		if (op_func == NULL)
		{
			fprintf(
				stderr,
				"L%d: unknown instruction %s\n",
				info->line,
				info->tokens[info->token_index]);
			exit(EXIT_FAILURE);
		}
		op_func(info);
		info->token_index++;
		info->line++;
	}
	return (0);
}
