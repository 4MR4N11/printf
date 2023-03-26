#include "main.h"

/**
 * _put_o - Prints an unsigned int argument as an octal number
 * @nb: The number to print
 * Return: The number of characters printed
 */

int	_put_o(unsigned int nb)
{
	unsigned int octal[11];
	int i, j, count;

	i = 0;
	j = 0;
	count = 0;
	while (nb > 0)
	{
		octal[i] = nb % 8;
		nb /= 8;
		i++;
	}
	if (i == 0)
	{
		_putchar('0');
		return (1);
	}
	j = i - 1;
	while (j >= 0)
	{
		_putchar(octal[j] + '0');
		count++;
		j--;
	}
	return (count);
}
