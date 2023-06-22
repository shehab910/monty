#include "monty.h"

/**
 * is_number - checks if a string is a number
 * @str: string to check
 * Return: 1 if true, 0 if false
 */
int is_number(char *str)
{
	int i = 0;

	if (str == NULL)
		return (0);

	if (str[0] == '-')
		i++;

	for (; str[i] != '\0'; i++)
	{
		if (isdigit(str[i]) == 0)
			return (0);
	}

	return (1);
}

/**
 * _strdup - duplicates a string
 * @s: string to duplicate
 * Return: pointer to the new string
 */
char *_strdup(const char *s)
{
	size_t len = strlen(s) + 1;
	void *new = malloc(len);

	if (new == NULL)
		return (NULL);

	return ((char *)memcpy(new, s, len));
}

/**
 * arr2dlen - gets the length of a 2d array
 * @arr: array to get length of
 * Return: length of array
 */
size_t arr2dlen(char **arr)
{
	size_t i = 0;

	if (arr == NULL)
		return (0);
	while (arr[i] != NULL)
		i++;
	return (i);
}

/**
 * is_whitespace - checks if a string is only whitespace
 * @str: string to check
 * Return: 1 if true, 0 if false
 */
int is_whitespace(char *str)
{
	int i = 0;

	if (str == NULL)
		return (0);

	for (; str[i] != '\0'; i++)
	{
		if (str[i] != ' ' && str[i] != '\t')
			return (0);
	}

	return (1);
}

/**
 * grace_exit - exit function
 * @info: monty info
 * @status: exit status
 */
void grace_exit(monty_info_t *info, int status)
{
	if (info->tokens != NULL)
		free(info->tokens);
	if (info->fileS != NULL)
		free(info->fileS);
	if (info->lines != NULL)
		free(info->lines);
	pop_all_stack_s(info);
	exit(status);
}
