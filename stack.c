#include "monty.h"

/**
 * push_stack_s - push a new node to the stack
 * @head: pointer to the head of the stack
 * @new_num: new number to be pushed
 * Return: 0 on success, 1 on failure
 */
int push_stack_s(monty_info_t *info, int new_num)
{
	stack_t *new_node = (stack_t *)malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, MALLOC_FAIL_ERR);
		return (1);
	}
	new_node->n = new_num;
	new_node->next = info->stack_head;
	info->stack_head = new_node;
	info->stack_size++;
	return (0);
}

/**
 * pop_stack_s - pop the top node of the stack
 * @info: pointer to the monty info struct
 * Return: 0 on success, 1 on failure
 */
int pop_stack_s(monty_info_t *info)
{
	stack_t *temp = info->stack_head;

	if (info->stack_head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", info->line);
		return (1);
	}
	info->stack_head = info->stack_head->next;
	free(temp);
	info->stack_size--;
	return (0);
}

/**
 * print_stack_s - print the stack
 * @head: pointer to the head of the stack
 * Return: 0 on success, 1 on failure
 */
int print_stack_s(stack_t *head)
{
	stack_t *temp = head;

	if (head == NULL)
		return (1);
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
	return (0);
}

/**
 * top_stack_s - gets the top node of the stack
 * @head: pointer to the head of the stack
 * Return: top node of the stack, 0 if empty
 */
int top_stack_s(stack_t *head)
{
	if (head == NULL)
		return (0);
	return (head->n);
}

/**
 * pop_all_stack_s - pop all nodes of the stack
 * @head: pointer to the head of the stack
 * Return: 0 on success, 1 on failure
 */
int pop_all_stack_s(monty_info_t *info)
{
	if (info->stack_head == NULL)
		return (1);
	while (info->stack_head != NULL)
		pop_stack_s(info);
	return (0);
}
