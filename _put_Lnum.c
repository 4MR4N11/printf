#include "main.h"

/**
 * _print_long - prints a number to stdout
 * @num: the number to print
 * @flags: struct that contains the flags to use
 * Return: the number of characters printed
 */

int _print_long(long num, flags_t flags)
{
	int count = 0;

	if (flags.h == 1)
		num = (short)num;
	else if (flags.h == 2)
		num = (char)num;
	else if (flags.l == 1)
		num = (long)num;
	if (num == -9223372036854775808)
	{
		count += _putstr("-9223372036854775808");
		return (count);
	}
	if (flags.plus && num >= 0)
		count += _putchar('+');
	else if (flags.space && num >= 0)
		count += _putchar(' ');
	if (num < 0)
	{
		count += _putchar('-');
		num = -num;
	}
	if (num == 0)
		count += _putchar('0');
	else
	{
		char num_str[21];
		int i = 0;

		while (num != 0)
		{
			num_str[i] = (num % 10) + '0';
			num /= 10;
			i++;
		}
		num_str[i] = '\0';
		for (i = i - 1; i >= 0; i--)
			count += _putchar(num_str[i]);
	}
	return (count);
}
