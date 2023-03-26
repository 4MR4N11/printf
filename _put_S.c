#include "main.h"

int put_S(char *str)
{
	int i = 0, count = 0;

	while (str && str[i])
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			count += _putchar('\\');
			count += _putchar('x');
			count += _put_X((unsigned int)str[i], 0);
		}
		else
		{
			count += _putchar(str[i]);
		}
		i++;
	}
	return (count);
}
