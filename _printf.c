#include <unistd.h> /* for write */
#include "main.h" /* include the header file with function prototypes */

/**
 * _printf - Custom implementation of printf function
 * @format: Format string containing zero or more directives
 *
 * Return: Number of characters printed (excluding the null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
	int count = 0; /* to keep track of characters printed */
	va_list args; /* to hold the variable arguments */
	char c; /* to store characters from format string */
	char *s; /* to store strings from format string */

	va_start(args, format); /* initialize variable arguments */
	while (format && *format) /* iterate through format string */
	{
		if (*format != '%') /* normal character */
		{
			_putchar(*format); /* print the character */
			count++;
			format++;
		}
		else /* conversion specifier */
		{
			format++; /* move past '%' */
			switch (*format)
			{
				case 'c':
					c = va_arg(args, int); /* get character argument */
					_putchar(c); /* print the character */
					count++;
					break;
				case 's':
					s = va_arg(args, char *); /* get string argument */
					if (s == NULL)
						s = "(null)"; /* handle NULL string */
					while (*s)
					{
						_putchar(*s); /* print the string character by character */
						count++;
						s++;
					}
					break;
				case '%':
					_putchar('%'); /* print a '%' character */
					count++;
					break;
				default:
					_putchar('%'); /* print the '%' character */
					_putchar(*format); /* print the unrecognized specifier */
					count += 2;
					break;
			}
			format++;
		}
	}
	va_end(args); /* clean up variable arguments */
	return count;
}

