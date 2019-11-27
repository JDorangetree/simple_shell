#include "orange.h"
/**
 * access_ - writes the character c to stdout
 * @arr: array to acces
 *
 **/

void access_(char **arr)
{
	pid_t pid_C;
	int status = 0;

	pid_C = fork();
	if (pid_C == -1)
		perror("Error:");
	if (pid_C == 0)
		execve(arr[0], arr, NULL);
	else
	{
		wait(&status);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
	}
}
