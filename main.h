#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int _printf(const char *format, ...);
int _print_binary(unsigned int num);
int _print_number(int num);
int _putchar(char c);
int _putstr(char *str);
int	_put_x(unsigned long nb);
int	_put_X(unsigned long nb);
int get_len(unsigned long nb);
int	_put_o(unsigned long nb);
int _put_u(unsigned int num);

#endif
