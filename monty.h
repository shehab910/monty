#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "errors.h"
/*
#define SAFE_PRINT(c) (write(STDOUT_FILENO, c, _strlen(c)))
#define SAFE_PRINT_ERR(c) (write(STDERR_FILENO, c, _strlen(c)))
*/
#define SUCCESS 0
#define FAILURE -1
#define TOKEN_SIZE 32

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
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct monty_info_s - monty global information/variables
 * @file: file pointer to the monty file
 * @line: line number of the monty file
 * @stack: pointer to the stack
 * @stack_size: size of the stack
 */
typedef struct monty_info_s
{
	FILE *file;
	unsigned int line;
	stack_t *stack_head;
	size_t stack_size;
} monty_info_t;

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
char **parse(char *str);

#endif /* MONTY_H */
