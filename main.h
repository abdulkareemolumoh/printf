#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _printf(const char *format, ...);
int _print_str(char *str);

/* Custom function prototypes */
int _printf(const char *format, ...);
char *_itoa(int value, char *buffer, int base);

/* Standard library function prototypes */
int _putchar(char c);
void _puts(char *str);
ssize_t _write(int fd, const void *buf, size_t count);

#endif /* MAIN_H */

