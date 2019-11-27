#include "orange.h"

/**
 * prerror - prints the erros
 * @argv: array of arguments
 * @array: array of arguments to execve
 * @count: counter of ocurrences
 * Return: void.
 */

void prerror(char *argv[], char *array[], int count)
{
	write(STDOUT_FILENO, argv[0], _strlen(argv[0]));
	write(STDOUT_FILENO, ": ", 2);
	print_n(count);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, array[0], _strlen(array[0]));
	write(STDOUT_FILENO, ":", 1);
	write(STDOUT_FILENO, " not found\n", 11);
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
}
