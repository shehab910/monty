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
 * _realloc - Reallocates a memory block using malloc and free
 * @ptr: A pointer to the memory previously allocated
 * @old_size: The size of the allocated space for ptr
 * @new_size: The size of the new memory block
 * Return: A pointer to the new memory block, NULL on failure
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *result;

	if (new_size == old_size)
		return (ptr);
	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}
	result = malloc(new_size);
	if (result == NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
	{
		arrayFill(result, '\0', new_size);
		free(ptr);
	}
	else
	{
		_memcpy(result, ptr, old_size);
		free(ptr);
	}
	return (result);
}

/**
 * _strcmp -  compares two strings.
 * @s1: pointer to the first string
 * @s2: pointer to the second string
 * Return: 0 if the strings can be considered identical,
 * otherwise return difference between
 * first two differing bytes
 */
int _strcmp(const char *s1, const char *s2)
{
	int i;

	if (s1 == NULL || s2 == NULL)
	{
		if (s1 == s2)
			return (0);
		else if (s1 == NULL)
			return (-1);
		else
			return (1);
	}
	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
			return ((s1[i] - s2[i]));
	}

	if (s1[i] == '\0' && s2[i] != '\0')
		return (-1);
	else if (s1[i] != '\0' && s2[i] == '\0')
		return (1);
	else
		return (0);
}

/**
 * _memcpy - Copies memory area
 * @dest: A pointer to the destination memory area
 * @src: A pointer to the source memory area
 * @n: The number of bytes to copy
 * Return: A pointer to the copied memory area @dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}

/**
 * arrayFill - Fills an array with a given element, length
 * @array: A pointer to array to be filled
 * @element: The element to fill the array with
 * @length: The length of the array
 * Return: A pointer to the filled array
 */
void *arrayFill(void *array, int element, unsigned int length)
{
	char *tmpPtr = array;
	unsigned int i = 0;

	while (i < length)
	{
		*tmpPtr = element;
		tmpPtr++;
		i++;
	}
	return (array);
}

char *_strdup(const char *s)
{
	size_t len = strlen(s) + 1;
	void *new = malloc(len);

	if (new == NULL)
		return NULL;

	return (char *)memcpy(new, s, len);
}

size_t arr2dlen(char **arr)
{
	size_t i = 0;

	if (arr == NULL)
		return (0);
	while (arr[i] != NULL)
		i++;
	return (i);
}

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
