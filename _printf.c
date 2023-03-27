#include "main.h"

/**
 * _putchar - writes a character to stdout
 * @c: the character to write
 *
 * Return: 1.
 */

int _putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

/**
 * skip_flags - skip flags after '%'.
 * @format: the format.
 * @index: index in format.
 * @flags: struct that contains the flags to use
 * Return: new index after skipping flags.
*/

int	skip_flags(const char *format, int index, flags_t *flags)
{
	while (format[index] == ' ' || format[index] == '+'
			|| format[index] == '#')
	{
		if (format[index] == ' ')
			flags->space = 1;
		if (format[index] == '+')
			flags->plus = 1;
		if (format[index] == '#')
			flags->hash = 1;
		index++;
	}
	return (index);
}

/**
 * check_format - checks for valid formats.
 * @c: format character.
 * Return: 1 if it's valid, otherwise 0.
*/
int check_format(char c)
{
	if (c == 'c' || c == 's' || c == '%' || c == 'X' || c == 'o'
		|| c == 'd' || c == 'b' || c == 'i' || c == 'x' ||
		c == 'u' || c == 'S' || c == 'p')
		return (1);
	return (0);
}

/**
 * print_content - prints content based on the conversion specifier
 * @list: the list of arguments to print
 * @conv: the conversion specifier to use
 * @flags: struct that contains the flags to use
 * Return: the number of characters printed
 */

int	print_content(va_list list, char conv, flags_t flags)
{
	int count;

	count = 0;
	if (conv == 'c')
		count = _putchar((char)va_arg(list, int));
	if (conv == 's')
		count = _putstr(va_arg(list, char *));
	if (conv == '%')
		count = _putchar(conv);
	if (conv == 'd' || conv == 'i')
		count = _print_number(va_arg(list, int), flags);
	if (conv == 'b')
		count = _print_binary(va_arg(list, unsigned int));
	if (conv == 'x')
		count = _put_x(va_arg(list, unsigned int), flags);
	if (conv == 'X')
		count = _put_X(va_arg(list, unsigned int), 1, flags);
	if (conv == 'o')
		count = _put_o(va_arg(list, unsigned int), flags);
	if (conv == 'u')
		count = _put_u(va_arg(list, unsigned int));
	if (conv == 'S')
		count = _put_S(va_arg(list, char*), flags);
	if (conv == 'p')
		count = _put_p(va_arg(list, void *), flags);
	return (count);
}

/**
 * _printf - prints formatted output to stdout
 * @format: the format string to use
 *
 * Return: the number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list list;
	flags_t flags = {0, 0, 0};
	int i = 0;
	int tmp;
	int count = 0;

	va_start(list, format);
	if (!format)
		return (-1);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			tmp = i;
			i = skip_flags(format, i + 1, &flags);
			if (!format[i])
				return (-1);
			if (check_format(format[i]))
			{
				count += print_content(list, format[i], flags);
				flags.plus = 0;
				flags.space = 0;
				flags.hash = 0;
			}
			else
			{
				if (!format[i])
					return (-1);
				while (tmp <= i)
					count += _putchar(format[tmp++]);
			}
		}
		else
			count += _putchar(format[i]);
		i++;
	}
	va_end(list);
	return (count);
}
