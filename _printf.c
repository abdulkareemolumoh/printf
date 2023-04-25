#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - Produces output according to a format.
 * @format: The format string.
 *
 * Return: The number of characters printed (excluding the null byte used to
 * end output to strings), or -1 if an error occurs.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int printed = 0;
	char ch;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (int i = 0; format[i]; i++)
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			printed++;
		}
		else
		{
			i++;
			if (format[i] == '\0')
			{
				va_end(args);
				return (-1);
			}

			switch (format[i])
			{
				case 'c':
					ch = va_arg(args, int);
					write(1, &ch, 1);
					printed++;
					break;
				case 's':
					printed += _print_str(va_arg(args, char *));
					break;
				case '%':
					write(1, &format[i], 1);
					printed++;
					break;
				default:
					write(1, "%", 1);
					write(1, &format[i], 1);
					printed += 2;
					break;
			}
		}
	}

	va_end(args);

	return (printed);
}

/**
 * _print_str - Prints a string.
 * @str: The string to print.
 *
 * Return: The number of characters printed.
 */
int _print_str(char *str)
{
	int i = 0;

	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}

	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}

	return (i);
}

