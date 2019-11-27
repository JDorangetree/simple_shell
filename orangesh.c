#include "orange.h"
#include <sys/types.h>
#include <sys/wait.h>

/**
 * ctrl_c - manage control c signal
 * @signum: void variable
 * Return: void
 */

void ctrl_c(int signum)
{
	(void) signum;
	write(STDOUT_FILENO, "\n", 1);
	write(STDOUT_FILENO, "$ ", 2);
}

/**
 * main - initializes the shell
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 on succes.
 */
int main(int argc, char *argv[])
{
	char *buffer = NULL, **array_to_execve;
	size_t size_bufer;
	int wc, count = 0, read;

	(void) argc;
	signal(SIGINT, ctrl_c);
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
	while ((read = getline(&buffer, &size_bufer, stdin)) != -1)
	{
		if (read == EOF)
		{
			free(buffer);
			return (0);
		}
		wc = word_count(buffer);
		array_to_execve = malloc(sizeof(char *) * (wc + 1));
		tokenizer(buffer, array_to_execve);
		count++;
		if (array_to_execve[0] != NULL && access(array_to_execve[0], X_OK) == 0)
			access_(array_to_execve);
		else if (array_to_execve[0] == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "$ ", 2);
		}
		else
			prerror(argv, array_to_execve, count);
		free(array_to_execve);
	}
	free(buffer);
	return (0);
}
