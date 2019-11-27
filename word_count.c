#include "orange.h"
/**
 * _strlen - returns the length of a string
 * @str: string to be measured
 * Return: length of string
 */
int _strlen(char *str)
{
	int len;

	len = 0;

	for (len = 0; str[len]; len++)
		;
	return (len);
}
/**
 * word_count - returns the length in words of a string
 * @str: string to be measured
 * Return: length of string
 */
int word_count(char *str)
{
	int contador = 1;
	int i = 0;
	int len = 0;

	len = _strlen(str);
	for (i = 0; i < len ; i++)
	{
		if (str[i] == ' ' && str[i + 1] != ' ' && str[i] != '\t')
		{
			contador++;
		}
	}
	return (contador);
}
