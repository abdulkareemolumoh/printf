#include <unistd.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - Custom implementation of printf function
 * @format: Format string
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, printed_chars = 0;

	if (!format)
		return (-1);

	va_start(args, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				return (-1);
			if (format[i] == 'c')
			{
				char c = va_arg(args, int);
				write(1, &c, 1);
				printed_chars++;
			}
			else if (format[i] == 's')
			{
				char *str = va_arg(args, char *);
				if (!str)
					str = "(null)";
				int len = _strlen(str);
				write(1, str, len);
				printed_chars += len;
			}
			else if (format[i] == '%')
			{
				write(1, &format[i], 1);
				printed_chars++;
			}
			else
			{
				write(1, &format[i - 1], 1);
				write(1, &format[i], 1);
				printed_chars += 2;
			}
		}
		else
		{
			write(1, &format[i], 1);
			printed_chars++;
		}
		i++;
	}
	va_end(args);

	return (printed_chars);
}

/**
 * _strlen - Custom implementation of strlen function
 * @s: String
 * Return: Length of string
 */
int _strlen(char *s)
{
	int len = 0;
	while (s && s[len])
		len++;
	return (len);
}

