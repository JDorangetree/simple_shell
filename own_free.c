#include "orange.h"
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
