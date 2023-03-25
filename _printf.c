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
 * Return: 1 if it's valid, 0 otherwise.
*/
int check_format(char c)
{
	if (c == 'c' || c == 's' || c == '%'
		|| c == 'd' || c == 'b')
		return (1);
	return (0);
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
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i = skip_space(format, i + 1);
			if (!format[i])
				return (-1);
			if (check_format(format[i]))
			{
				if (format[i] == 'c')
					count += _putchar(va_arg(list, int));
				if (format[i] == 's')
					count += _putstr(va_arg(list, char *));
				if (format[i] == '%')
					count += _putchar(format[i]);
				if (format[i] == 'd' || format[i] == 'i')
					count += _print_number(va_arg(list, int));
				if (format[i] == 'b')
					count += _print_binary(va_arg(list, unsigned int));
			}
			else
			{
				count += _putchar('%');
				count += _putchar(format[i]);
			}
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}
	return (count);
}
