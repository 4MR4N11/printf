#include "main.h"

int _printf(const char *format, ...)
{
	va_list list;
	int i = 0;
	int count = 0;
	char arg;

	va_start(list, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
			{
				arg = va_arg(list, int);
				write(1, &arg, 1);
				count++;
			}
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}
	return count;
}
