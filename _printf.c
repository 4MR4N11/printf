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
 * _putstr - writes a string to stdout
 * @str: the string to write
 *
 * Return: the number of characters written
 */

int _putstr(char *str)
{
	int i;
	int len;

	len = 0;
	i = 0;
	while (str[i])
	{
		len += _putchar(str[i]);
		i++;
	}
	return (len);
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
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
				count += _putchar(va_arg(list, int));
			if (format[i] == 's')
				count += _putstr(va_arg(list, char *));
			if (format[i] == '%')
				count += _putchar(format[i]);
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
