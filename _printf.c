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
	while (str && str[i])
	{
		len += _putchar(str[i]);
		i++;
	}
	return (len);
}

/**
 * _print_number - prints a number to stdout
 * @num: the number to print
 *
 * Return: the number of characters printed
 */

int _print_number(int num)
{
	int count = 0;

	if (num < 0)
	{
		count += _putchar('-');
		num = -num;
	}
	if (num == 0)
	{
		count += _putchar('0');
	}
	else
	{
		char num_str[12];
		int i = 0;

		while (num != 0)
		{
			num_str[i] = (num % 10) + '0';
			num /= 10;
			i++;
		}
		num_str[i] = '\0';
		for (i = i - 1; i >= 0; i--)
		{
			count += _putchar(num_str[i]);
		}
	}
	return (count);
}

/**
 * _print_binary - prints the binary representation of an unsigned int
 * @num: the unsigned int to print
 *
 * Return: the number of characters printed
 */

int _print_binary(unsigned int num)
{
	int i = 0, j;
	unsigned int count = 0;
	unsigned int arr[64];

	if (num == 0)
	{
		count += _putchar(0 + '0');
	}
	else
	{
		for (; num > 0;)
		{
			arr[i++] = num % 2;
			num /= 2;
		}
		for (j = i - 1; j >= 0; j--)
		{
			count += _putchar(arr[j] + '0');
		}
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
	int i = 0;
	int count = 0;

	va_start(list, format);
	while (format && format[i])
	{
		if (!format || (format[0] == '%' && !format[1]))
			return (-1);
		if (format[0] == '%' && format[1] == ' ' && !format[2])
			return (-1);
		if (format[i] == '%')
		{
			i++;
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
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}
	return (count);
}
