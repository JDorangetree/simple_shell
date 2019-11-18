#include "orange.h"

int main (void)
{
    char *buffer, **input_array;
    size_t size_bufer = 1;
    ssize_t read;

    printf("$ ");
    buffer = malloc(sizeof(char)* size_bufer);
    if(buffer == NULL)
        return(0);
    while ((read = getline(&buffer, &size_bufer, stdin)) != -1)
    {
        input_array = strtow(buffer);
        execve(input_array[0], input_array, NULL);

    }
    printf("$ ");
    free(buffer);
    return(read);
}
