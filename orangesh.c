#include "orange.h"

int main (int argc, char *argv[])
{
    (void)argc;
    char *buffer, *input_string, **array_to_execve;
    size_t size_bufer = 1, mcount = 10;
    ssize_t read;
    pid_t pid_C;
    int number, exc, i;
    char s[4] = " \n\t";
    pid_t my_pid;

    printf("$ ");
    buffer = malloc(sizeof(char)* size_bufer);
    if(buffer == NULL)
        return(0);
    while ((read = getline(&buffer, &size_bufer, stdin)) != -1)
    {
        i = 0;
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
        while( (array_to_execve[i] = strtok( buffer, s )) != NULL)
        {
            i++;
            if (i == mcount)
            {
                array_to_execve = own_realloc(array_to_execve, &mcount);
                if (array_to_execve == NULL)
                {
                    perror("Fatal Error");
                    return(1);
                }
            }
            buffer = NULL;
        }
        if (pid_C == 0)
        {
            exc = execve(array_to_execve[0], array_to_execve, NULL);
            if(exc == -1)
                printf("%u%s: No such file or directory\n$",my_pid = getpid(), argv[0]);
        }
        else
        {
            wait(&number);
            printf("$ ");
        }
    }
    free(buffer);
    return(read);
}
