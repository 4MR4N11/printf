#include "main.h"

/**
 * print_content - prints content based on the conversion specifier
 * @list: the list of arguments to print
 * @conv: the conversion specifier to use
 * @flags: struct that contains the flags to use
 * Return: the number of characters printed
 */

int     print_content(va_list list, char conv, flags_t flags)
{
	int count;

	count = 0;
	if (conv == 'c')
		count = _putchar((char)va_arg(list, int));
	if (conv == 's')
		count = _putstr(va_arg(list, char *));
	if (conv == '%')
		count = _putchar(conv);
	if (conv == 'b')
		count = _print_binary(va_arg(list, unsigned int));
	if (conv == 'S')
		count = _put_S(va_arg(list, char*), flags);
	if (conv == 'p')
		count = _put_p(va_arg(list, void *), flags);
	count += print_content2(list, conv, flags);
	return (count);
}

/**
 * print_content2 - prints content based on the conversion specifier
 * @list: the list of arguments to print
 * @conv: the conversion specifier to use
 * @flags: struct that contains the flags to use
 * Return: the number of characters printed
 */

int print_content2(va_list list, char conv, flags_t flags)
{
	int count;

	count = 0;

	if (conv == 'd' || conv == 'i')
	{
		if (flags.l == 1)
			count = _print_long(va_arg(list, long), flags);
		else if (flags.l == 0)
			count = _print_number(va_arg(list, int), flags);
	}
	if (conv == 'u')
	{
		if (flags.l == 1)
			count = _put_Lu(va_arg(list, unsigned long int), flags);
		else if (flags.l == 0)
			count = _put_u(va_arg(list, unsigned int), flags);
	}
	if (conv == 'o')
	{
		if (flags.l == 1)
			count = _put_Lo(va_arg(list, unsigned long int), flags);
		else if (flags.l == 0)
			count = _put_o(va_arg(list, unsigned int), flags);
	}
	if (conv == 'X')
	{
		if (flags.l == 1)
			count = _put_LX(va_arg(list, unsigned long int), 1, flags);
		else if (flags.l == 0)
			count = _put_X(va_arg(list, unsigned int), 1, flags);
	}
	if (conv == 'x')
	{
		if (flags.l == 1)
			count = _put_Lx(va_arg(list, unsigned long int), flags);
		else if (flags.l == 0)
			count = _put_x(va_arg(list, unsigned int), flags);
	}
	return (count);
}
