#include "main.h"

/**
 * get_len - calculates the length of a number
 * @nb: the number to calculate the length of
 * Return: the length of the number
 */

int get_len(unsigned int nb)
{
	int i;

	i = 0;
	while (nb)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

/**
 * _put_x - Converts and prints an unsigned long int to lowercase hexadecimal.
 * @nb: The unsigned long integer to be printed.
 * Return: The number of characters printed.
 */

int	_put_x(unsigned int nb)
{
	char *base = "0123456789abcdef";
	char *rev_num;
	int i, j;

	i = 0;
	if (nb == 0)
		return (_putchar('0'));
	rev_num = malloc(sizeof(char) * get_len(nb));
	while (nb > 0)
	{
		j = nb % 16;
		nb = nb / 16;
		rev_num[i++] = base[j];
	}
	j = 0;
	while (--i >= 0)
		j += _putchar(rev_num[i]);
	free(rev_num);
	return (j);
}
