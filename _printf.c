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
	int printed = 0;
	char ch;
	char buffer[1024]; /* Buffer to store characters to be printed */
	int buffer_index = 0; /* Index to keep track of buffer position */
	char *str;

	if (format == NULL)
		return (-1);

	va_list args;
	va_start(args, format);

	for (int i = 0; format[i]; i++)
	{
		if (format[i] != '%')
		{
			buffer[buffer_index++] = format[i];
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
					buffer[buffer_index++] = ch;
					printed++;
					break;
				case 's':
					str = va_arg(args, char *);
					if (str == NULL)
						str = "(null)";
					while (*str)
					{
						buffer[buffer_index++] = *str;
						str++;
						printed++;
					}
					break;
				case '%':
					buffer[buffer_index++] = '%';
					printed++;
					break;
				default:
					buffer[buffer_index++] = '%';
					buffer[buffer_index++] = format[i];
					printed += 2;
					break;
			}
		}
	}

	va_end(args);

	/* Write characters from buffer to stdout */
	write(1, buffer, buffer_index);

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
	char ch;

	if (str == NULL)
	{
		ch = '(';
		write(1, &ch, 1);
		ch = 'n';
		write(1, &ch, 1);
		ch = 'u';
		write(1, &ch, 1);
		ch = 'l';
		write(1, &ch, 1);
		ch = 'l';
		write(1, &ch, 1);
		ch = ')';
		write(1, &ch, 1);
		return (6);
	}

	while (str[i])
	{
		ch = str[i];
		write(1, &ch, 1);
		i++;
	}

	return (i);
}

