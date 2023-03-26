#include "main.h"

/**
 * _put_u - Print an unsigned integer as a decimal integer.
 * @num: The unsigned integer to print.
 *
 * Return: The number of characters printed, or -1 if an error occurred.
 */

int _put_u(unsigned int num)
{
	unsigned int i = 4294967295;
	int count = 0, j = 0;
	char Unum[20];

	if (num == 0)
	{
		count += _putchar('0');
	}

	if (num > i)
	{
		return (-1);
	}
	else
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
