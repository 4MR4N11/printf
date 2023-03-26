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

	if (num > i)
	{
		count = _putchar('0');
		return (-1);
	}
	else if ((int)num < 0)
	{
		i -= num - 1;
		while (i > 0)
		{
			Unum[j++] = (i % 10) + '0';
			i /= 10;
		}
		Unum[j] = '\0';
	}
	else
	{
		while (num > 0)
		{
			Unum[j++] = num % 10 + '0';
			num /= 10;
		}
		Unum[j] = '\0';
	}
	j = j - 1;
	while (j > 0)
	{
		count += _putchar(Unum[j]);
		j--;
	}
	return (count);
}
