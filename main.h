#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

// Function prototypes
int _printf(const char *format, ...);
int _print_str(char *str);

---------------------

#define BUFF_SIZE 1024 // Buffer size for printing

// Function prototypes
int print_int(va_list types, char buffer[], int flags, int width, int precision, int size);
int write_number(int is_negative, int i, char buffer[], int flags, int width, int precision, int size);

// Macro for unused parameters
#define UNUSED(x) (void)(x)

#endif /* MAIN_H */

