#include "orange.h"

int main (char **argv)
{
    char *buffer, **input_array;
    size_t size_bufer = 1;
    ssize_t read;
    pid_t pid_C;
    int number, exc;

    printf("$ ");
    buffer = malloc(sizeof(char)* size_bufer);
    if(buffer == NULL)
        return(0);
    while ((read = getline(&buffer, &size_bufer, stdin)) != -1)
    {
        pid_C = fork();
        if (pid_C == -1)
        {
            perror("Error:");
            return(1);
        }
        input_array = strtow(buffer);
        if (pid_C == 0)
            exc = execve(input_array[0], input_array, NULL);
                if (exc == -1)
                    printf("%s: No such file or directory\n$", argv[0]);

        else
        {
            wait(&number);
            printf("$ ");
        }
    }
    free(buffer);
    return(read);
}
