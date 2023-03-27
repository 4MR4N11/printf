#include "main.h"

/**
 * _put_p - Prints the address of a pointer.
 * @ptr: The pointer to be printed.
 * Return: The number of characters printed.
 */

int	_put_p(void *ptr)
{
	char *base = "0123456789abcdef";
	char *rev_num;
	int i, j;
	unsigned long tmp = (unsigned long)ptr;

	i = 0;
	if (!ptr)
		return (_putstr("(nil)"));
	rev_num = malloc(sizeof(char) * get_len(tmp));
	if (rev_num == NULL)
		exit(-1);
	while (tmp > 0)
	{
		j = tmp % 16;
		tmp = tmp / 16;
		rev_num[i++] = base[j];
	}
	j = 0;
	j += _putstr("0x");
	while (--i >= 0)
		j += _putchar(rev_num[i]);
	free(rev_num);
	return (j);
}
