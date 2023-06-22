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
 * tokenize - tokenizes a string
 * @str: string to tokenize
 * @delim: delimiter to tokenize by
 * Return: array of tokens
 */

char **tokenize(char *str, const char *delim)
{
	char **tokens;
	char *token;
	unsigned long int token_count = 0;
	int i = 0;
	char *temp_str = _strdup(str);

	if (temp_str == NULL)
	{
		fprintf(stderr, MALLOC_FAIL_ERR);
		exit(EXIT_FAILURE);
	}
	token = strtok(temp_str, delim);
	while (token != NULL)
	{
		token_count++;
		token = strtok(NULL, delim);
	}
	free(temp_str);

	tokens = malloc(sizeof(char *) * (token_count + 1));
	if (tokens == NULL)
	{
		fprintf(stderr, MALLOC_FAIL_ERR);
		free(str);
		exit(EXIT_FAILURE);
	}

	token = strtok(str, delim);
	while (token != NULL)
	{
		tokens[i] = token;
		token = strtok(NULL, delim);
		i++;
	}
	tokens[i] = NULL;

	return (tokens);
}

/**
 * parse_to_lines - parses a string into lines
 * @str: string to parse
 * Return: array of tokens
 */
char **parse_to_lines(char *str)
{
	return (tokenize(str, "\n"));
}
/**
 * parse_line - parses a line into tokens
 * @line: line to parse
 * Return: array of tokens
 */
char **parse_line(char *line)
{
	return (tokenize(line, " \t"));
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
