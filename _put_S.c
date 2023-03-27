#include "main.h"

/**
 * _put_S - outputs a string to the standard output,
 * with non-printable characters replaced by
 * \x followed by the ASCII code value in hexadecimal
 * @str: pointer to the string to output
 * @flags: struct that contains the flags to use
 * Return: the number of characters printed to the standard output
 */

int _put_S(char *str, flags_t flags)
{
	int i = 0, count = 0;

	while (str && str[i])
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			count += _putchar('\\');
			count += _putchar('x');
			flags.hash = 0;
			count += _put_X((unsigned int)str[i], 0, flags);
		}
		else
		{
			count += _putchar(str[i]);
		}
		i++;
	}
	return (count);
}
