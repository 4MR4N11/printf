# Custom printf function

This is an implementation of the `printf()` function in C that supports the `%c` and `%s` format specifiers. The function is implemented in the _printf.c file, and it depends on the `unistd.h` and `stdarg.h` libraries.

## Usage

To use the custom printf() function, you can include the `main.h` header file in your C program and call the `_printf()` function with a format string and any necessary arguments. For example:

```#include "main.h"

int main(void)
{
    _printf("Hello, %s!\n", "world");
    return 0;
}
```

This would output the following text to the console:

```
Hello, world!
```

The custom `printf()` function currently supports only the %c and %s format specifiers, which correspond to a single character and a null-terminated string, respectively.

## Files

- [\_printf.c](./_printf.c): The main source file that contains the implementation of the custom `_printf()` function.
- [main.h](./main.c): The header file that defines the interface for the custom printf() function and includes the necessary library headers.
- [README.md](./README.md): This file, which provides an overview of the code and instructions for how to use it.

