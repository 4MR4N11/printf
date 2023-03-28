#include "main.h"

/**
 * _put_Lx - Converts and prints an unsigned long int to lowercase hexadecimal.
 * @nb: The unsigned long integer to be printed.
 * @flags: struct that contains the flags to use
 * Return: The number of characters printed.
 */

int	_put_Lx(unsigned long int nb, flags_t flags)
{
	char *base = "0123456789abcdef";
	char *rev_num;
	int i, j;

	i = 0;
	if (nb == 0)
		return (_putchar('0'));
	if (flags.h == 1)
		nb = (unsigned short)nb;
	else if (flags.h == 2)
		nb = (unsigned char)nb;
	else if (flags.l == 1)
		nb = (unsigned long)nb;
	rev_num = malloc(sizeof(char) * get_len(nb));
	if (rev_num == NULL)
		exit(-1);
	while (nb > 0)
	{
		j = nb % 16;
		nb = nb / 16;
		rev_num[i++] = base[j];
	}
	j = 0;
	if (flags.hash)
		j += _putstr("0x");
	while (--i >= 0)
		j += _putchar(rev_num[i]);
	free(rev_num);
	return (j);
}
