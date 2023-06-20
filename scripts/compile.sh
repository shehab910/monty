#!/bin/bash
if [ "$1" == "w" ]; then
	gcc -Wall -Wextra -pedantic -std=c89 *.c -o monty
else
	gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
fi
