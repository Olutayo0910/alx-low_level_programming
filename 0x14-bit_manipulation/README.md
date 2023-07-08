Bit Manipulation in C
This project focuses on bit manipulation and the use of bitwise operators in the C programming language. It consists of several tasks that involve working with binary numbers, setting and clearing bits, converting between binary and decimal representations, and checking endianness.

Learning Objectives
By completing this project, you will be able to:

Look for the right source of information without too much help
Manipulate bits and use bitwise operators effectively
Requirements
Allowed editors: vi, vim, emacs
All files will be compiled on Ubuntu 20.04 LTS using gcc, with the following flags: -Wall -Werror -Wextra -pedantic -std=gnu89
All files should end with a new line
A README.md file, at the root of the folder, is mandatory
Code should follow the Betty style and be free of any errors or warnings
Only the standard C library functions malloc, free, and exit are allowed
The prototype for the _putchar function should be included in the main.h header file
No more than 5 functions are allowed per file
Global variables are not allowed
The use of functions like printf, puts, calloc, realloc, etc. is forbidden
Tasks
Task 0: binary_to_uint
Write a function that converts a binary number to an unsigned int.

Prototype: unsigned int binary_to_uint(const char *b);
The parameter b is a pointer to a string of 0 and 1 characters representing a binary number
The function returns the converted number as an unsigned int
If b is NULL or contains characters other than 0 and 1, the function returns 0
Task 1: print_binary
Write a function that prints the binary representation of a number.

Prototype: void print_binary(unsigned long int n);
The function takes an unsigned long int as a parameter and prints its binary representation
It does not use arrays, malloc, or the % or / operators
Task 2: get_bit
Write a function that returns the value of a bit at a given index.

Prototype: int get_bit(unsigned long int n, unsigned int index);
The function takes an unsigned long int n and an index index
It returns the value of the bit at the specified index or -1 if an error occurs
Task 3: set_bit
Write a function that sets the value of a bit to 1 at a given index.

Prototype: int set_bit(unsigned long int *n, unsigned int index);
The function takes a pointer to an unsigned long int n and an index index
It sets the bit at the specified index to 1 and returns 1 on success or -1 if an error occurs
Task 4: clear_bit
Write a function that sets the value of a bit to 0 at a given index.

Prototype: int clear_bit(unsigned long int *n, unsigned int index);
The function takes a pointer to an unsigned long int n and an index index
It sets the bit at the specified index to 0 and returns 1 on success or -1 if an error occurs
Task 5: flip_bits
Write a function that returns the number of bits needed to flip to get from one number to another.

Prototype: unsigned int flip_bits(unsigned long int n, unsigned long int m);
The function takes two unsigned long ints, n and m
It returns the number of bits that need to be flipped in n to obtain m
Task 6: Endianness
Write a function that checks the endianness of the system.

Prototype: int get_endianness(void);
The function returns 0 if the system is big endian or 1 if it is little endian
Task 7: Crackme3
Find the password for the provided program and save it in the file 101-password.

Run the program using the provided password as a command-line argument
The correct password should display the message "Congratulations!"
General Information
This project is part of the ALX Low-Level Programming curriculum. It helps in understanding the concepts of bit manipulation and bitwise operators in the C programming language.

Please refer to the individual task files for more detailed instructions and examples.
