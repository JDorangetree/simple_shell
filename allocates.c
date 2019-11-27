#include "orange.h"

/**
 * tokenizer - custom function to free an array of pointer
 * @size: number of words
 * @buffer: array to tokenize
 * Return: words tokenized double pointer
 */

char **tokenizer(int size, char *buffer)
{
	char **array_to_execve;
	char s[4] = " \n\t";
	int i;


	array_to_execve = malloc(sizeof(char *) * size + 1);
	if (array_to_execve == NULL)
	{
		free(buffer);
		perror("Fatal Error");
		return (NULL);
	}
	i = 0;
	while ((array_to_execve[i] = strtok(buffer, s)) != NULL)
	{
		i++;
		buffer = NULL;
	}
	array_to_execve[i] = NULL;
	return (array_to_execve);
}
/**
 * own_free - custom function to free an array of pointer
 * @source: array to free
 * Return: void
 */
void own_free(char **source)
{
	int i = 0;

	while (source[i])
		free(source[i++]);
	free(source);
}
