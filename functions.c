#include "main.h"
#include <unistd.h>

/**
 * _putchar - Writes a character to stdout
 * @c: The character to be written
 *
 * Return: On success, return the character written. On error, return -1.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_number - Prints an integer to stdout
 * @n: The integer to be printed
 *
 * Return: Number of digits printed
 */
int print_number(int n)
{
	int num_digits = 0;

	/* Handle negative numbers */
	if (n < 0)
	{
		_putchar('-');
		num_digits++;
		n = -n;
	}

	/* Print digits in reverse order */
	if (n / 10)
		num_digits += print_number(n / 10);
	_putchar('0' + n % 10);
	num_digits++;

	return (num_digits);
}

