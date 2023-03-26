#include "main.h"
#include <stdio.h>

int main()
{
	int count = 0, count1 = 0;
	unsigned int i = 4294967295;
	count = _printf("%u\n", i);
	printf("%d\n", count);
	count1 = printf("%u\n", i);
	printf("%d\n", count1);
	return (0);
}
