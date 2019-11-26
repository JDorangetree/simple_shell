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
	size_t size_bufer,i;
    int wc;
	ssize_t read;
	pid_t pid_C;

	(void) argc;
    signal(SIGINT, ctrl_c);
	printf("$ ");
	while ((read = getline(&buffer, &size_bufer, stdin)) != -1)
	{   
        if (read == EOF)
        {
            free (buffer);
        }
        wc = word_count(buffer);
		array_to_execve = malloc (sizeof(char *) * wc);
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
        if (access(array_to_execve[0], X_OK) == 0)
        {
            pid_C = fork();
            if (pid_C == -1)
            {   
                free(buffer);
                perror("Error:");
            }
            if (pid_C == 0)
               execve(array_to_execve[0], array_to_execve, NULL);
               printf("$ ");
               wait(NULL);
        }
        else
		{
            if (array_to_execve[0] == NULL)
                printf("$ ");
            else
                printf("%s: No such file or directory\n$ ", argv[0]);
		}
	}
    free(buffer);
	return(0);
}


