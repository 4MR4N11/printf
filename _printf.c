#include "main.h"

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
	while (format[index] == 'l' || format[index] == 'h')
	{
		if (format[index] == 'l')
			flags->l++;
		if (format[index] == 'h')
			flags->h++;
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
 * print_else - prints the rest of the string
 * if no conversion specifier is found
 * @format: the format string to use
 * @i: the index of the format string
 * @tmp: the index of the format string
 * Return: the number of characters printed
*/
int print_else(const char *format, int i, int tmp)
{
	int count = 0;

	if (!format[i])
		return (-1);
	while (tmp <= i)
	{
		if (format[tmp] == 'l' && format[tmp - 1] == '%')
		{
			if (format[tmp + 1] == 'l')
				tmp++;
			tmp++;
		}
		else if (format[tmp] == 'h' && format[tmp - 1] == '%')
		{
			if (format[tmp + 1] == 'h')
				tmp++;
			tmp++;
		}
		count += _putchar(format[tmp++]);
	}
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
	flags_t flags = {0, 0, 0, 0, 0};
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
			if ((check_format(format[i])) && ((flags.l <= 2 && !flags.h)
				|| (flags.h <= 2 && !flags.l)))
			{
				count += print_content(list, format[i], flags);
				flags.plus = 0;
				flags.space = 0;
				flags.hash = 0;
				flags.l = 0;
				flags.h = 0;
			}
			else
				count += print_else(format, i, tmp);
		}
		else
			count += _putchar(format[i]);
		i++;
	}
	va_end(list);
	return (count);
}
