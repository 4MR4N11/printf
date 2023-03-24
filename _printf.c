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
 * _print_number - prints a number to stdout
 * @n: the number to print
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
			if (format[i] == 'd' || format[i] == 'i')
				count += _print_number(va_arg(list, int));
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
