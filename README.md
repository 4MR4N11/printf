# Custom printf function

This repository contains a custom implementation of the printf function in C.

## Functionality

The custom printf function supports the following format specifiers:

- `%c`: print a single character
- `%s`: print a null-terminated string
- `%d`: print a decimal integer
- `%i`: print an integer
- `%b`: print an unsigned integer in binary format
- `%x`: print an unsigned integer in lowercase hexadecimal format
- `%X`: print an unsigned integer in uppercase hexadecimal format
- `%o`: Prints an unsigned integer in octal format.
- `%%`: print a literal percent sign

## File Structure

The source code for the custom printf function is organized as follows:

- `_printf.c`: contains the implementation for the custom printf function
- `_put_bin.c`: contains the implementation for printing unsigned integers in binary format
- `_put_num.c`: contains the implementation for printing decimal and integer values
- `_put_X.c`: contains the implementation for printing unsigned integers in uppercase hexadecimal format
- `_put_x.c`: contains the implementation for printing unsigned integers in lowercase hexadecimal format
- `_putstr.c`: contains the implementation for printing null-terminated strings
- `_put_o.c`: Function that prints an unsigned integer in octal format.
- `main.h`: contains the function prototypes and necessary header files.

## Usage

To use the custom printf function in your own program, simply include the main.h header file and call the function with the desired format string and any necessary arguments.

Example usage:
```
#include "main.h"

int main(void)
{
    _printf("%s %d %b %X %o\n", "Hello, world!", 42, 42, 255, 42);
    return (0);
}
```

This will output:
```
Hello, world! 42 101010  FF 52
```

## Testing

The custom printf function has been tested on a variety of input strings and format specifiers. To run the test suite, simply compile and run a main file along with all the files:
```
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 -Wno-format *.c -o test_printf
./test_printf
```
This will compile and run the test suite, which will output the results of each test.

## Authors

- Khalid El Amrani ([@4MR4N11](https://github.com/4mr4n11)).
- Anas Benba ([@AnasBenba](https://github.com/AnasBenba)).