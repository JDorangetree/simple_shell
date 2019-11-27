#include "orange.h"
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 **/
 
void access_(char **arr)
{
    pid_t pid_C;

    pid_C = fork();
    if (pid_C == -1)
        perror("Error:");
    if (pid_C == 0)
        execve(arr[0], arr, NULL);
    else
	{
		wait(NULL);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
    }
}
