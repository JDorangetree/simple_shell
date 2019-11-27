#include "orange.h"
/**
 * exit_ - Handle exit command
 * @argv: string
 * @n: code number
 * Description: Handle exit command
 * Return: Integer
 */
void exit_(char *argv, int n)
{
	char *str = "exit";
	int i = 0;

	while (argv[i] > 'a' && argv[i] < 'z' && argv[i] == str[i])
		i++;
	if (i == 4)
	{
		free(argv);
		if (n != 512)
			exit(n);
		else
			exit(2);
	}
}
