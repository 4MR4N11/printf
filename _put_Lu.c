#include "main.h"

/**
 * _put_Lu - Print an unsigned long integer as a decimal integer.
 * @num: The unsigned long integer to print.
 * @flags: struct that contains the flags to use
 * Return: The number of characters printed, or -1 if an error occurred.
 */

int _put_Lu(unsigned long int num, flags_t flags)
{
	unsigned long int i = ULONG_MAX;
	int count = 0, j = 0;
	char Unum[20];

	if (flags.h == 1)
		num = (short)num;
	else if (flags.h == 2)
		num = (unsigned char)num;
	else if (flags.l == 1)
		num = (unsigned long)num;
	if (num == 0)
		count += _putchar('0');
	if (num > i)
		return (-1);
	if (num > 0)
	{
		while (num > 0)
		{
			Unum[j] = num % 10 + '0';
			num /= 10;
			j++;
		}
	}
	while (--j >= 0)
	{
		count += _putchar(Unum[j]);
	}
	return (count);
}
