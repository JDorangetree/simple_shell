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
	pid_t pid_C;

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
		array_to_execve = tokenizer(wc, buffer);
		count++;
		if (access(array_to_execve[0], X_OK) == 0)
		{
			pid_C = fork();
			if (pid_C == -1)
				perror("Error:");
			if (pid_C == 0)
				execve(array_to_execve[0], array_to_execve, NULL);
			else
			{
				wait(NULL);
				if (isatty(STDIN_FILENO))
					write(STDOUT_FILENO, "$ ", 2);
			}
		}
		else
		{
			prerror(argv, array_to_execve, count);
		}
	}
	free(buffer);
	return (0);
}
