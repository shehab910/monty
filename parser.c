#include "monty.h"

/**
 * sReadFile - reads a file and returns a string
 * containing the contents of the file
 * @filename: name of the file to read
 * Return: string containing the contents of the file
 */
char *sReadFile(char *filename)
{
	FILE *fp;
	char *buffer;
	long file_size;

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	fseek(fp, 0, SEEK_END);
	file_size = ftell(fp);
	rewind(fp);

	buffer = malloc(sizeof(char) * file_size);
	if (buffer == NULL)
	{
		fprintf(stderr, MALLOC_FAIL_ERR);
		exit(EXIT_FAILURE);
	}

	fread(buffer, 1, file_size, fp);
	fclose(fp);

	return (buffer);
}

/**
 * parse - parses a string into tokens
 * @str: string to parse
 * Return: array of tokens
 */
char **parse(char *str)
{
	char **tokens;
	char *token;
	int i = 0;

	tokens = malloc(sizeof(char *) * TOKEN_SIZE);
	if (tokens == NULL)
	{
		fprintf(stderr, MALLOC_FAIL_ERR);
		exit(EXIT_FAILURE);
	}

	token = strtok(str, " \n\t");
	while (token != NULL)
	{
		tokens[i] = token;
		token = strtok(NULL, " \n\t");
		i++;
	}
	tokens[i] = NULL;

	return (tokens);
}

/**
 * free_tokens - frees an array of tokens
 * @tokens: array of tokens to free
 */
void free_tokens(char **tokens)
{
	int i = 0;

	while (tokens[i] != NULL)
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

/**
 * print_tokens - prints an array of tokens
 * @tokens: array of tokens to print
 */
void print_tokens(char **tokens)
{
	int i = 0;

	while (tokens[i] != NULL)
	{
		printf("tokens[%d] = %s\n", i, tokens[i]);
		i++;
	}
}