#include "orange.h"

int main (void)
{
    char *buffer;
    size_t size_bufer;
    ssize_t read;

    printf("$ ");
    buffer = malloc(sizeof(char)* size_bufer);
    if(buffer == NULL)
        return(0);
    while ((getline(&buffer, &size_bufer, stdin)) != -1);
    {
        printf("%s$ ", buffer);
    }
    printf("\n");
    free(buffer);
    return(0);
}
