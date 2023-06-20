#include "monty.h"

int main(void)
{
	monty_info_t info;
	stack_t *head = NULL;
	int new_num = 0;

	info.stack_head = head;
	info.stack_size = 0;
	info.line = 1;

	char *fileS = sReadFile("bytecodes/00.m");
	printf("%s", fileS);

	return (0);
}