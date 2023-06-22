#include "monty.h"

/**
 * push_op - push a new node to the stack
 * @info: pointer to the monty info struct
 */
void push_op(monty_info_t *info)
{
	char *arg;
	int new_num;

	if (info == NULL)
		grace_exit(info, EXIT_FAILURE);
	if (info->tokens_len < 2)
	{
		fprintf(stderr, "L%d: usage: push integer\n", info->line);
		grace_exit(info, EXIT_FAILURE);
	}
	arg = info->tokens[1];
	new_num = 0;

	if (arg == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", info->line);
		grace_exit(info, EXIT_FAILURE);
	}
	if (is_number(arg) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", info->line);
		grace_exit(info, EXIT_FAILURE);
	}
	new_num = atoi(arg);
	if (push_stack_s(info, new_num) == 1)
		grace_exit(info, EXIT_FAILURE);
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
		grace_exit(info, EXIT_FAILURE);
	}
	printf("%d\n", head->n);
}

/**
 * pop_op - remove the top element of the stack
 * @info: pointer to the monty info struct
 */
void pop_op(monty_info_t *info)
{
	pop_stack_s(info);
}

/**
 * swap_op - swap the top two elements of the stack
 * @info: pointer to the monty info struct
 */
void swap_op(monty_info_t *info)
{
	stack_t *head = info->stack_head;
	int temp;

	if (head == NULL || head->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", info->line);
		grace_exit(info, EXIT_FAILURE);
	}
	temp = head->n;
	head->n = head->next->n;
	head->next->n = temp;
}
