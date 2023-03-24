# Custom printf function

This is an implementation of the printf() function in C that supports the %c and %s format specifiers. The function is implemented in the main.c file, and it depends on the `unistd.h` and `stdarg.h` libraries.

## Usage

To use the custom printf() function, you can include the main.h header file in your C program and call the `_printf()` function with a format string and any necessary arguments. For example:

```#include "main.h"

int main(void)
{
    _printf("Hello, %s!\n", "world");
    return 0;
}

test
