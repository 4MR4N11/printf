#include "main.h"

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
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str && str[i])
	{
		len += _putchar(str[i]);
		i++;
	}
	return (len);
}
