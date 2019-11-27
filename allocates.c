#include "orange.h"

/**
 * tokenizer - custom function to tokenize an array of pointer
 * @buffer: array to tokenize
 * @array_to_execve: array to execve
 * Return: words tokenized double pointer
 */

void tokenizer(char *buffer, char **array_to_execve)
{
	char s[4] = " \n\t";
	int i;

	i = 0;
	while ((array_to_execve[i] = strtok(buffer, s)) != NULL)
	{
		i++;
		buffer = NULL;
	}
	array_to_execve[i] = NULL;
	i = 0;
	while (array_to_execve[i])
	{
		if (array_to_execve[i][0] == '#')
		{
			array_to_execve[i] = NULL;
		}
		i++;
	}
}
