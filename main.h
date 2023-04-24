#ifndef MAIN_H
#define MAIN_H

/* Include necessary libraries */
#include <stdarg.h> /* for va_list */
#include <unistd.h> /* for write() */

/* Define constants */
#define BUFF_SIZE 1024 /* buffer size for storing characters */

/* Function prototypes */
int _printf(const char *format, ...);
void print_buffer(char buffer[], int *buff_ind);
int get_flags(const char *format, int *index);
int get_width(const char *format, int *index, va_list args);
int get_precision(const char *format, int *index, va_list args);
int get_size(const char *format, int *index);
int handle_print(const char *format, int *index, va_list args,
		char buffer[], int flags, int width, int precision, int size);

#endif /* MAIN_H */

