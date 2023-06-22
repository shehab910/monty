#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

#include "errors.h"
/*
 * #define SAFE_PRINT(c) (write(STDOUT_FILENO, c, _strlen(c)))
 * #define SAFE_PRINT_ERR(c) (write(STDERR_FILENO, c, _strlen(c)))
 */
#define SUCCESS 0
#define FAILURE -1

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct monty_info_s - monty global information/variables
 * @file: file pointer to the monty file
 * @line: line number of the monty file
 * @stack_head: pointer to the stack
 * @stack_size: size of the stack
 * @tokens: array of tokens
 * @tokens_len: length of the tokens array
 * @token_index: index of the current token
 * Description: monty global information/variables
 */
typedef struct monty_info_s
{
	FILE *file;
	unsigned int line;
	stack_t *stack_head;
	size_t stack_size;
	char **tokens;
	size_t tokens_len;
	unsigned int token_index;

} monty_info_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(monty_info_t *info);
} instruction_t;

/* stack.c */
int push_stack_s(monty_info_t *info, int new_num);
int pop_stack_s(monty_info_t *info);
int print_stack_s(stack_t *head);
int top_stack_s(stack_t *head);
int pop_all_stack_s(monty_info_t *info);

/* parser.c */
char *sReadFile(char *filename);
void print_tokens(char **tokens);
void free_tokens(char **tokens);
char **parse_to_lines(char *str);
char **parse_line(char *str);
char **tokenize(char *str, const char *delim);

/* operations.c */
void (*get_op_func(char *s))(monty_info_t *info);
int op_handler(monty_info_t *info);
void push_op(monty_info_t *info);
void pall_op(monty_info_t *info);
int new_op_handler(monty_info_t *info, char *line);
instruction_t get_instruction(char *opcode);
void pint_op(monty_info_t *info);
void pop_op(monty_info_t *info);
void swap_op(monty_info_t *info);

/* utils.c */
int is_number(char *str);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int _strcmp(const char *s1, const char *s2);
char *_memcpy(char *dest, char *src, unsigned int n);
void *arrayFill(void *array, int element, unsigned int length);
char *_strdup(const char *s);
size_t arr2dlen(char **arr);
int is_whitespace(char *str);

#endif /* MONTY_H */
