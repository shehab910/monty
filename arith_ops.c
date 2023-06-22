#include "monty.h"

/**
 * add_op - adds the top two elements of the stack
 * @info: pointer to the monty info struct
 */
void add_op(monty_info_t *info)
{
	int sum;

	if (info->stack_head == NULL || info->stack_head->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", info->line);
		exit(EXIT_FAILURE);
	}
	sum = info->stack_head->n + info->stack_head->next->n;
	pop_stack_s(info);
	info->stack_head->n = sum;
}

/**
 * sub_op - subtract the top two elements of the stack
 * @info: pointer to the monty info struct
 */
void sub_op(monty_info_t *info)
{
	int sub;

	if (info->stack_head == NULL || info->stack_head->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", info->line);
		exit(EXIT_FAILURE);
	}
	sub = info->stack_head->next->n - info->stack_head->n;
	pop_stack_s(info);
	info->stack_head->n = sub;
}

/**
 * div_op - divide the top two elements of the stack
 * @info: pointer to the monty info struct
 */
void div_op(monty_info_t *info)
{
	int div;

	if (info->stack_head == NULL || info->stack_head->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", info->line);
		exit(EXIT_FAILURE);
	}
	if (info->stack_head->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", info->line);
		exit(EXIT_FAILURE);
	}
	div = info->stack_head->next->n / info->stack_head->n;
	pop_stack_s(info);
	info->stack_head->n = div;
}

/**
 * mul_op - multiply the top two elements of the stack
 * @info: pointer to the monty info struct
 */
void mul_op(monty_info_t *info)
{
	int mul;

	if (info->stack_head == NULL || info->stack_head->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", info->line);
		exit(EXIT_FAILURE);
	}
	mul = info->stack_head->n * info->stack_head->next->n;
	pop_stack_s(info);
	info->stack_head->n = mul;
}

/**
 * mod_op - compute the modulus of the top two elements of the stack
 * @info: pointer to the monty info struct
 */
void mod_op(monty_info_t *info)
{
	int mod;

	if (info->stack_head == NULL || info->stack_head->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", info->line);
		exit(EXIT_FAILURE);
	}
	if (info->stack_head->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", info->line);
		exit(EXIT_FAILURE);
	}
	mod = info->stack_head->next->n % info->stack_head->n;
	pop_stack_s(info);
	info->stack_head->n = mod;
}
