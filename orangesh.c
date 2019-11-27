#include "orange.h"
#include <sys/types.h>
#include <sys/wait.h>

void ctrl_c(int signum)
{
	(void) signum;
	write(STDOUT_FILENO, "\n", 1);
	write(STDOUT_FILENO, "$ ", 2);
}
void own_free(char **source)
{
	int i = 0;
	while (source[i])
		free(source[i++]);
	free(source);
}

int main (int argc, char *argv[])
{
	char *buffer = NULL;
	char **array_to_execve;
	char s[4] = " \n\t";
	size_t size_bufer,i;
	int wc, count = 0;
	ssize_t read;
	pid_t pid_C;

	(void) argc;
	signal(SIGINT, ctrl_c);
	if (isatty(STDIN_FILENO))
		printf("$ ");
	while ((read = getline(&buffer, &size_bufer, stdin)) != -1)
	{
		if (read == EOF)
		{
			free (buffer);
			return(0);
		}
		wc = word_count(buffer);
		array_to_execve = malloc (sizeof(char *) * wc + 1);
		if (array_to_execve == NULL)
			{
				free(buffer);
				perror("Fatal Error");
				return(-1);
			}
		i = 0;
		while((array_to_execve[i] = strtok(buffer, s)) != NULL)
		{
			i++;
			buffer = NULL;
		}
		array_to_execve[i] = NULL;
		count++;
		if (access(array_to_execve[0], X_OK) == 0)
		{
			pid_C = fork();
			if (pid_C == -1)
			{
				free(array_to_execve);
				perror("Error:");
			}
			if (pid_C == 0)
			{
				execve(array_to_execve[0], array_to_execve, NULL);
				free(array_to_execve);
			}
			else
			{
				wait(NULL);
				if (isatty(STDIN_FILENO))
					printf("$ ");
			}
		}
		else
		{
			printf("%s: %i: %s: not found\n", argv[0], count, array_to_execve[0]);
			if (isatty(STDIN_FILENO))
				printf("$ ");
			free(array_to_execve);
		}
	}
	free(buffer);
	return(0);
}
