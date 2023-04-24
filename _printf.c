#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - Custom printf function
 * @format: Format string
 *
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
	int i, len = 0;
	char c;
	char *s;
	va_list arg;

	va_start(arg, format);
	for (i = 0; format && format[i]; i++)
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					c = va_arg(arg, int);
					write(1, &c, 1);
					len++;
					break;
				case 's':
					s = va_arg(arg, char *);
					if (s == NULL)
						s = "(null)";
					while (*s)
					{
						write(1, s, 1);
						s++;
						len++;
					}
					break;
				case '%':
					write(1, &format[i], 1);
					len++;
					break;
				default:
					write(1, "%", 1);
					write(1, &format[i], 1);
					len += 2;
					break;
			}
		}
		else
		{
			write(1, &format[i], 1);
			len++;
		}
	}
	va_end(arg);

	return (len);
}

