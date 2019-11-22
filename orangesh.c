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
	char *buffer; 
	char **array_to_execve; 
	char s[4] = " \n\t";
	size_t size_bufer = 1, mcount = 1024, i;
	ssize_t read;
	pid_t pid_C, number;

	int exc;

	(void) argc;
    signal(SIGINT, ctrl_c);
	printf("$ ");
	buffer = malloc(sizeof(char)* size_bufer);
	if(buffer == NULL)
		return(0);
	while ((read = getline(&buffer, &size_bufer, stdin)) != -1)
	{   
        if (read == EOF)
        {
            free (buffer);
            return(0);
        }
		pid_C = fork();
		if (pid_C == -1)
		{
			perror("Error:");
			return(1);
		}
		array_to_execve = malloc (sizeof(char *) * mcount);
		if (array_to_execve == NULL)
			{
				perror("Fatal Error");
				return(1);
			}
		i = 0;	
		while( (array_to_execve[i] = strtok(buffer, s)) != NULL)
		{
			i++;
			buffer = NULL;
		}
		if (pid_C == 0)
		{
			exc = execve(array_to_execve[0], array_to_execve, NULL);
			if(exc == -1)
				printf("%s: No such file or directory\n$ ", argv[0]);
            own_free(array_to_execve);
		}
		else
		{
			wait(&number);
			printf("$ ");
            own_free(array_to_execve);
		}
	}
	free(buffer);
	return(read);
}
