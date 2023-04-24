#include "main.h"
#include <unistd.h>

/**
 * _putchar - Custom putchar function
 * @c: Character to be printed
 * Return: 1 on success, -1 on error
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _printf - Custom printf function
 * @format: Format string
 * Return: Number of printed characters
 */
int _printf(const char *format, ...)
{
	int printed_chars = 0;
	va_list args;
	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				break;
			else if (*format == '%')
			{
				_putchar('%');
				printed_chars++;
			}
			else if (*format == 'c')
			{
				int c = va_arg(args, int);
				_putchar(c);
				printed_chars++;
			}
			else if (*format == 's')
			{
				char *s = va_arg(args, char *);
				if (s == NULL)
					s = "(null)";
				while (*s)
				{
					_putchar(*s);
					s++;
					printed_chars++;
				}
			}
			else
			{
				_putchar('%');
				_putchar(*format);
				printed_chars += 2;
			}
		}
		else
		{
			_putchar(*format);
			printed_chars++;
		}
		format++;
	}

	va_list args;
	int printed_chars = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				return (-1);
			switch (*format)
			{
				case 'd':
				case 'i':
					printed_chars += _print_int(va_arg(args, int));
					break;
				default:
					_putchar('%');
					_putchar(*format);
					printed_chars += 2;
					break;
			}
		}
		else
		{
			_putchar(*format);
			printed_chars++;
		}
		format++;
	}

	va_end(args);
	return (printed_chars);
}

