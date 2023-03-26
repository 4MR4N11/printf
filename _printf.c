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
 * skip_space - skip spaces after '%'.
 * @format: the format.
 * @index: index in format.
 * Return: new index after skipping spaces.
*/

int	skip_space(const char *format, int index)
{
	while (format[index] == ' ')
		index++;
	return (index);
}

/**
 * check_format - checks for valid formats.
 * @c: format character.
 * Return: 1 if it's valid, otherwise 0.
*/
int check_format(char c)
{
	if (c == 'c' || c == 's' || c == '%' || c == 'X'
		|| c == 'd' || c == 'b' || c == 'i' || c == 'x')
		return (1);
	return (0);
}

/**
 * print_content - prints content based on the conversion specifier
 * @list: the list of arguments to print
 * @conv: the conversion specifier to use
 * Return: the number of characters printed
 */

int	print_content(va_list list, char conv)
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
		count = _print_number(va_arg(list, int));
	if (conv == 'b')
		count = _print_binary(va_arg(list, unsigned int));
	if (conv == 'x')
		count = _put_x(va_arg(list, unsigned long));
	if (conv == 'X')
		count = _put_X(va_arg(list, unsigned long));
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
	int i = 0;
	int count = 0;

	va_start(list, format);
	if (!format)
		return (-1);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i = skip_space(format, i + 1);
			if (!format[i])
				return (-1);
			if (check_format(format[i]))
				count += print_content(list, format[i]);
			else
			{
				count += _putchar('%');
				count += _putchar(format[i]);
			}
		}
		else
			count += _putchar(format[i]);
		i++;
	}
	va_end(list);
	return (count);
}
