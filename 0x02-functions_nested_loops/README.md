# 0x02. C - Functions, nested loops

## Resources

[* Nested while loops](https://www.youtube.com/watch?v=Z3iGeQ1gIss)

[* C - Functions](http://www.tutorialspoint.com/cprogramming/c_functions.htm)

[* Learning to Program in C](https://www.youtube.com/watch?v=qMlnFwYdqIw)

[* What is the purpose of a function prototype?](https://www.geeksforgeeks.org/what-is-the-purpose-of-a-function-prototype/)

[* C - Header Files](https://www.tutorialspoint.com/cprogramming/c_header_files.htm)

## General

What are nested loops and how to use them

What is a function and how do you use functions

What is the difference between a declaration and a definition of a function

What is a prototype

Scope of variables

What are the gcc flags -Wall -Werror -pedantic -Wextra -std=gnu89

What are header files and how to to use them with #include

## Requirements

### General

Allowed editors: vi, vim, emacs

All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89

All your files should end with a new line

A README.md file, at the root of the folder of the project is mandatory

Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl

You are not allowed to use global variables

No more than 5 functions per file

You are not allowed to use the standard library. Any use of functions like printf, puts, etc… is forbidden

You are allowed to use _putchar

You don’t have to push _putchar.c, we will use our file. If you do it won’t be taken into account

In the following examples, the main.c files are shown as examples. You can use them to test your functions, but you don’t have to push them to your repo (if you do we won’t take them into account). We will use our own main.c files at compilation. Our main.c files might be different from the one shown in the examples

The prototypes of all your functions and the prototype of the function _putchar should be included in your header file called main.h

Don’t forget to push your header file

## More Info

You do not have to understand the call by reference (address), stack, static variables, recursions or arrays, yet.

## Tasks

### 0. _putchar - mandatory

Write a program that prints _putchar, followed by a new line.

      * The program should return 0

-----
julien@ubuntu:~/0x02$  gcc -Wall -pedantic -Werror -Wextra -std=gnu89 _putchar.c 0-putchar.c -o 0-putchar

julien@ubuntu:~/0x02$ ./0-putchar

_putchar

----

### 1. I sometimes suffer from insomnia. And when I can't fall asleep, I play what I call the alphabet game - mandatory

Write a function that prints the alphabet, in lowercase, followed by a new line.

      * Prototype: void print_alphabet(void);

      * You can only use _putchar twice in your code

-----
julien@ubuntu:~/0x02$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 _putchar.c 1-main.c 1-alphabet.c -o 1-alphabet

julien@ubuntu:~/0x02$ ./1-alphabet

abcdefghijklmnopqrstuvwxyz

----

### 2. 10 x alphabet - mandatory

Write a function that prints 10 times the alphabet, in lowercase, followed by a new line.

      * Prototype: void print_alphabet_x10(void);

      * You can only use _putchar twice in your code
----
julien@ubuntu:~/0x02$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 _putchar.c 2-main.c 2-print_alphabet_x10.c -o 2-alphabet_x10

julien@ubuntu:~/0x02$ ./2-alphabet_x10

abcdefghijklmnopqrstuvwxyz

abcdefghijklmnopqrstuvwxyz

abcdefghijklmnopqrstuvwxyz

abcdefghijklmnopqrstuvwxyz

abcdefghijklmnopqrstuvwxyz

abcdefghijklmnopqrstuvwxyz

abcdefghijklmnopqrstuvwxyz

abcdefghijklmnopqrstuvwxyz

abcdefghijklmnopqrstuvwxyz

abcdefghijklmnopqrstuvwxyz

----

### 3. islower - mandatory

Write a function that checks for lowercase character.

      * Prototype: int _islower(int c);

      * Returns 1 if c is lowercase

      * Returns 0 otherwise

FYI: The standard library provides a similar function: islower. Run man islower to learn more.

----
julien@ubuntu:~/0x02$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 _putchar.c 3-main.c 3-islower.c -o 3-islower

julien@ubuntu:~/0x02$ ./3-islower

011

-----

### 4. isalpha - mandatory

Write a function that checks for alphabetic character.

      * Prototype: int _isalpha(int c);

      * Returns 1 if c is a letter, lowercase or uppercase

      * Returns 0 otherwise

FYI: The standard library provides a similar function: isalpha. Run man isalpha to learn more.

----
julien@ubuntu:~/0x02$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 _putchar.c 4-main.c 4-isalpha.c -o 4-isalpha

julien@ubuntu:~/0x02$ ./4-isalpha

1110

----

### 5. Sign - mandatory

Write a function that prints the sign of a number.

* Prototype: int print_sign(int n);

* Returns 1 and prints + if n is greater than zero

* Returns 0 and prints 0 if n is zero

* Returns -1 and prints - if n is less than zero

----
root@e000a5a9f6d4:~/alx-low_level_programming/0x02-functions_nested_loops# ./5-sign 

+, 1

0, 0

+, 1

-, /

----

### 6. There is no such thing as absolute value in this world. You can only estimate what a thing is worth to you - mandatory

Write a function that computes the absolute value of an integer.

* Prototype: int _abs(int);

FYI: The standard library provides a similar function: abs. Run man abs to learn more.

----
root@e000a5a9f6d4:~/alx-low_level_programming/0x02-functions_nested_loops# ./6-abs 

1

0

1

98

----

### 7. There are only 3 colors, 10 digits, and 7 notes; it's what we do with them that's important - mandatory

Write a function that prints the last digit of a number.

* Prototype: int print_last_digit(int);

* Returns the value of the last digit

----
root@e000a5a9f6d4:~/alx-low_level_programming/0x02-functions_nested_loops# ./7-last_digit 

8044

----

### 8. I'm federal agent Jack Bauer, and today is the longest day of my life - mandatory

Write a function that prints every minute of the day of Jack Bauer, starting from 00:00 to 23:59.

* Prototype: void jack_bauer(void);

* You can listen to [this soundtrack](https://www.youtube.com/watch?v=btAfXqgMkPs) while coding :)

----
root@e000a5a9f6d4:~/alx-low_level_programming/0x02-functions_nested_loops# ./8-24 | head

00:00

00:01

00:02

00:03

00:04

00:05

00:06

00:07

00:08

00:09

root@e000a5a9f6d4:~/alx-low_level_programming/0x02-functions_nested_loops# ./8-24 | tail

23:50

23:51

23:52

23:53

23:54

23:55

23:56

23:57

23:58

23:59

root@e000a5a9f6d4:~/alx-low_level_programming/0x02-functions_nested_loops# ./8-24 | wc -l

1440

----

### 9. Learn your times table - mandatory

Write a function that prints the 9 times table, starting with 0.

* Prototype: void times_table(void);

* Format: see example

----
root@e000a5a9f6d4:~/alx-low_level_programming/0x02-functions_nested_loops# ./9-times_table 

0,  0,  0,  0,  0,  0,  0,  0,  0,  0

0,  1,  2,  3,  4,  5,  6,  7,  8,  9

0,  2,  4,  6,  8, 10, 12, 14, 16, 18

0,  3,  6,  9, 12, 15, 18, 21, 24, 27

0,  4,  8, 12, 16, 20, 24, 28, 32, 36

0,  5, 10, 15, 20, 25, 30, 35, 40, 45

0,  6, 12, 18, 24, 30, 36, 42, 48, 54

0,  7, 14, 21, 28, 35, 42, 49, 56, 63

0,  8, 16, 24, 32, 40, 48, 56, 64, 72

0,  9, 18, 27, 36, 45, 54, 63, 72, 81

root@e000a5a9f6d4:~/alx-low_level_programming/0x02-functions_nested_loops# ./9-times_table | tr ' ' . 

0,..0,..0,..0,..0,..0,..0,..0,..0,..0

0,..1,..2,..3,..4,..5,..6,..7,..8,..9

0,..2,..4,..6,..8,.10,.12,.14,.16,.18

0,..3,..6,..9,.12,.15,.18,.21,.24,.27

0,..4,..8,.12,.16,.20,.24,.28,.32,.36

0,..5,.10,.15,.20,.25,.30,.35,.40,.45

0,..6,.12,.18,.24,.30,.36,.42,.48,.54

0,..7,.14,.21,.28,.35,.42,.49,.56,.63

0,..8,.16,.24,.32,.40,.48,.56,.64,.72

0,..9,.18,.27,.36,.45,.54,.63,.72,.81

----