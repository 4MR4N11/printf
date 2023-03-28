#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

/**
 * struct flags - struct that contains the flags to use
 * @plus: flag to print a plus sign
 * @space: flag to print a space
 * @hash: flag to print a hash
 * @l: flag to print a l
 * @h: flag to print a h
 */
typedef struct flags
{
	int plus;
	int space;
	int hash;
	int l;
	int h;
} flags_t;
int _printf(const char *format, ...);
int _print_binary(unsigned int num);
int _print_number(int num, flags_t flags);
int _putchar(char c);
int _putstr(char *str);
int	_put_x(unsigned int nb, flags_t flags);
int	_put_X(unsigned int nb, int check, flags_t flags);
int get_len(unsigned long int nb);
int     _put_LX(unsigned long int nb, int check, flags_t flags);
int	_put_o(unsigned int nb, flags_t flags);
int _put_u(unsigned int num, flags_t flags);
int _put_S(char *str, flags_t flags);
int _put_p(void *ptr, flags_t flags);
int _print_long(long num, flags_t flags);
int _put_Lu(unsigned long int num, flags_t flags);
int     _put_Lo(unsigned long int nb, flags_t flags);
int     _put_Lx(unsigned long int nb, flags_t flags);
int print_content2(va_list list, char conv, flags_t flags);
int print_content(va_list list, char conv, flags_t flags);

#endif
