#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
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
	char *buffer;

	if (!format)
		return (-1);

	buffer = malloc(sizeof(char) * 1024);
	if (!buffer)
		return (-1);

	va_start(args, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
			{
				free(buffer);
				return (-1);
			}
			printed_chars += handle_format(&format[i], args, buffer, &i);
		}
		else
		{
			buffer[printed_chars] = format[i];
			printed_chars++;
			if (printed_chars == 1024)
			{
				write(1, buffer, printed_chars);
				printed_chars = 0;
			}
			i++;
		}
	}
	va_end(args);
	write(1, buffer, printed_chars);
	free(buffer);
	return (printed_chars);
}

/**
 * handle_format - Handles the conversion specifiers in format string
 * @format: Format string
 * @args: va_list of arguments
 * @buffer: Buffer to store printed characters
 * @i: Pointer to current position in format string
 * Return: Number of characters printed
 */
int handle_format(const char *format, va_list args, char *buffer, int *i)
{
	int j = 0, printed_chars = 0;
	char *str;

	switch (format[j])
	{
		case 'c':
			buffer[printed_chars] = va_arg(args, int);
			printed_chars++;
			(*i)++;
			break;
		case 's':
			str = va_arg(args, char *);
			if (!str)
				str = "(null)";
			printed_chars += _strlen(str);
			_strncpy(&buffer[printed_chars], str, _strlen(str));
			(*i)++;
			break;
		case '%':
			buffer[printed_chars] = '%';
			printed_chars++;
			(*i)++;
			break;
		case 'd':
		case 'i':
			printed_chars += handle_integers(format, args, buffer, &j);
			(*i) += j + 1;
			break;
		case 'b':
			printed_chars += handle_binary(args, buffer);
			(*i)++;
			break;
		case 'u':
		case 'o':
		case 'x':
		case 'X':
			printed_chars += handle_unsigned(format, args, buffer, &j);
			(*i) += j + 1;
			break;
		case 'S':
			str = va_arg(args, char *);
			if (!str)
				str = "(null)";
			printed_chars += handle_non_printable_string(str, buffer);
			(*i)++;
			break;
		case 'p':
			printed_chars += handle_pointer(args, buffer);
			(*i)++;
			break;
		case 'r':
			str = va_arg(args, char *);
			if (!str)
				str = "(null)";
			printed_chars += handle_reverse_string(str, buffer);
			(*i)++;
			break;
		case 'R':
			str = va_arg(args, char *);
			if (!str)
				str = "(null)";
			print

