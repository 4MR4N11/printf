#include "main.h"

/**
 * _print_number - prints a number to stdout
 * @num: the number to print
 * @flags: struct that contains the flags to use
 * Return: the number of characters printed
 */

int _print_number(int num, flags_t flags)
{
	int count = 0;

	if (num == -2147483648)
	{
		count += _putstr("-2147483648");
		return (count);
	}

	if (flags.plus && num >= 0)
		count += _putchar('+');
	if (num < 0)
	{
		count += _putchar('-');
		num = -num;
	}
	if (num == 0)
		count += _putchar('0');
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
			count += _putchar(num_str[i]);
	}
	return (count);
}
