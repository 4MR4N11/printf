#include "main.c"

/**
 * _print_binary - prints the binary representation of an unsigned int
 * @num: the unsigned int to print
 *
 * Return: the number of characters printed
 */

int _print_binary(unsigned int num)
{
        int i = 0, j;
        unsigned int count = 0;
        unsigned int arr[64];

        if (num == 0)
        {
                count += _putchar(0 + '0');
                return(0);
        }

        for (; num > 0;)
        {
                arr[i++] = num % 2;
                num /= 2;
        }

        for (j = i - 1; j >= 0; j--)
        {
                count += _putchar(arr[j] + '0');
        }
        return (count);
}
