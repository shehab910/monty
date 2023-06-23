#include "monty.h"

/**
 * nop_op - do nothing
 * @info: pointer to the monty info struct
 */
void nop_op(monty_info_t *info)
{
	(void)info;
}

/**
 * pchar_op - prints the char at the top of the stack
 * @info: pointer to the monty info struct
 */
void pchar_op(monty_info_t *info)
{

	if (info->stack_head == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range", info->line);
		grace_exit(info, EXIT_FAILURE);
	}
	if (__isascii(info->stack_head->n))
	{
		fprintf(stderr, "L%d: can't pchar, stack empty", info->line);
		grace_exit(info, EXIT_FAILURE);
	}
	printf("%c\n", info->stack_head->n);
}

/**
 * pstr_op - prints the string starting at the top of the stack
 * @info: pointer to the monty info struct
 */
void pstr_op(monty_info_t *info)
{
	stack_t *tmp = info->stack_head;

	while (tmp != NULL)
	{
		if (__isascii(tmp->n) && tmp->n != 0)
			printf("%c", tmp->n);
		else
			break;
		tmp = tmp->next;
	}
	printf("\n");
}

/**
 * rotl_op - rotates the stack to the top
 * @info: pointer to the monty info struct
 */
void rotl_op(monty_info_t *info)
{
	stack_t *tmp = info->stack_head;

	if (info->stack_head == NULL || info->stack_head->next == NULL)
		return;

	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = info->stack_head;
	info->stack_head->prev = tmp;
	info->stack_head = info->stack_head->next;
	info->stack_head->prev->next = NULL;
	info->stack_head->prev = NULL;
}

/**
 * rotr_op - rotates the stack to the bottom
 * @info: pointer to the monty info struct
 */
void rotr_op(monty_info_t *info)
{
	stack_t *tmp = info->stack_head;

	if (info->stack_head == NULL || info->stack_head->next == NULL)
		return;

	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = info->stack_head;
	info->stack_head->prev = tmp;
	info->stack_head = tmp;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
}
