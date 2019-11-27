#include "orange.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}


/**
 * print_n - print number n with putchar
 *
 * @n: number to print
 *
 * Return: always void
 */
void print_n(int n)
{
	if (n < 0)
	{
		_putchar('-');
		print_unsigned_int(-(int)n);
	}
	else
		print_unsigned_int(n);
}
/**
 * print_unsigned_int - prints an unsigned integer
 *
 * @n: an unsigned integer to print
 *
 * Return: always void
 */
void print_unsigned_int(int n)
{
	if (n / 10 != 0)
	{
		print_unsigned_int(n / 10);
	}
	_putchar((n % 10) + '0');
}
