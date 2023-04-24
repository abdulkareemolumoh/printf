/**
 * _itoa - converts an integer to a string
 * @value: the integer value to convert
 * @buffer: the buffer to store the resulting string
 * @base: the numerical base to use (typically 10)
 *
 * Return: a pointer to the resulting string
 */
char *_itoa(int value, char *buffer, int base)
{
	// handle negative values
	if (value < 0)
	{
		*buffer++ = '-';
		value = -value;
	}

	// convert the value to a string in reverse order
	char *p = buffer;
	do
	{
		*p++ = "0123456789abcdef"[value % base];
		value /= base;
	} while (value);

	// add a null terminator and reverse the string
	*p = '\0';
	char *q = buffer;
	if (*q == '-')
	{
		++q; // skip over the negative sign
	}
	for (--p; q < p; ++q, --p)
	{
		char temp = *q;
		*q = *p;
		*p = temp;
	}

	return buffer;
}


#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: the format string
 * @...: additional arguments to print
 *
 * Return: the number of characters printed (excluding the null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);

	int count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			++format;
			if (*format == 'd' || *format == 'i')
			{
				int value = va_arg(args, int);
				char buffer[12];
				_puts(_itoa(value, buffer, 10));
				++count;
			}
			else if (*format == '%')
			{
				_putchar('%');
				++count;
			}
		}
		else
		{
			_putchar(*format);
			++count;
		}
		++format;
	}

	va_end(args);
	return count;
}

