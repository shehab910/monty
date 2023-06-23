#include "monty.h"

const instruction_t opcodes[] = {
	{"push", push_op},
	{"pall", pall_op},
	{"pint", pint_op},
	{"pop", pop_op},
	{"swap", swap_op},
	{"add", add_op},
	{"nop", nop_op},
	{"sub", sub_op},
	{"div", div_op},
	{"mul", mul_op},
	{"mod", mod_op},
	{"pchar", pchar_op},
	{"pstr", pstr_op},
	{"rotl", rotl_op},
	{"rotr", rotr_op},
	{NULL, NULL}};

/**
 * get_instruction - gets the instruction from the opcode
 * @opcode: the opcode
 * Return: the instruction
 */
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
 * op_handler - executes one opcode (one line)
 * @info: pointer to the monty info struct
 * @line: the line to execute
 * Return: 0 on success, 1 on failure
 */
int op_handler(monty_info_t *info, char *line)
{
	instruction_t instruction;
	char **tokens;
	char *dupline;

	dupline = _strdup(line);
	if (dupline == NULL)
		grace_exit(info, EXIT_FAILURE);
	info->dup = dupline;

	tokens = parse_line(dupline);

	if (tokens == NULL)
	{
		return (1);
	}

	instruction = get_instruction(tokens[0]);

	if (instruction.opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", info->line, tokens[0]);
		grace_exit(info, EXIT_FAILURE);
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
	info->dup = dupline = NULL;
	return (0);
}
