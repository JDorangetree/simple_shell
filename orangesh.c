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
	while (i <= 9)
    {
			free(source[i]);
            i++;
    }
    free(source);
}

int main (int argc, char *argv[])
{
	char *buffer = NULL; 
	char **array_to_execve; 
	char s[4] = " \n\t";
	size_t size_bufer, mcount = 10, i;
	ssize_t read;
	pid_t pid_C;
	int exc;

	(void) argc;
    signal(SIGINT, ctrl_c);
	printf("$ ");
	while ((read = getline(&buffer, &size_bufer, stdin)) != -1)
	{   
        if (read == EOF)
        {
            free (buffer);
        }
        pid_C = fork();
		if (pid_C == -1)
		{
			perror("Error:");
            free(buffer);
			return(1);
		}
		array_to_execve = malloc (sizeof(char *) * mcount);
		if (array_to_execve == NULL)
			{
				perror("Fatal Error");
				return(1);
			}
		i = 0;
		while((array_to_execve[i] = strtok(buffer, s)) != NULL)
		{
			i++;
			buffer = NULL;
         
		}
		if (pid_C == 0)
		{
			exc = execve(array_to_execve[0], array_to_execve, NULL);
			if(exc == -1)
            {
				printf("%s: No such file or directory\n$ ", argv[0]);
            }
	    }
		else
		{
			wait(NULL);
			printf("$ ");
		}
	}
    free(buffer);
	return(0);
}
