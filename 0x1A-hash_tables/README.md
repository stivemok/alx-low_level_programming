# 0x1A. C - Hash tables

## Resources

[* What is a HashTable Data Structure - Introduction to Hash Tables , Part 0](https://www.youtube.com/watch?v=MfhjkfocRR0)

[* Hash function](https://en.wikipedia.org/wiki/Hash_function)

[* Hash table](https://en.wikipedia.org/wiki/Hash_table)

[* All about hash tables](https://www.digitalocean.com/community/tutorials/hash-table-in-c-plus-plus)

[* why hash tables and not arrays](https://stackoverflow.com/questions/31930046/what-is-a-hash-table-and-how-do-you-make-it-in-c)
#
## General

* What is a hash function

* What makes a good hash function

* What is a hash table, how do they work and how to use them

* What is a collision and what are the main ways of dealing with collisions in the context of a hash table

* What are the advantages and drawbacks of using hash tables

* What are the most common use cases of hash tables

## Requirements

### General

* Allowed editors: vi, vim, emacs

* All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89

* All your files should end with a new line

* A README.md file, at the root of the folder of the project is mandatory

* Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl

* You are not allowed to use global variables

* No more than 5 functions per file

* You are allowed to use the C standard library

* The prototypes of all your functions should be included in your header file called hash_tables.h

* Don’t forget to push your header file

* All your header files should be include guarded

### Python Dictionaries

Python dictionaries are implemented using hash tables. When you will be done with this project, you will be able to better understand the power and simplicity of Python dictionaries. So much is actually happening when you type d = {'a': 1, 'b': 2}, but everything looks so simple for the user. Python doesn’t use the exact same implementation than the one you will work on today though. If you are curious on how it works under the hood, here is a good blog post about [how dictionaries are implemented in Python 2.7](http://www.laurentluce.com/cgi-sys/suspendedpage.cgi) (not mandatory).

Note that all dictionaries are not implemented using hash tables and there is a difference between a dictionary and a hash table. [Read more here](https://stackoverflow.com/questions/2061222/what-is-the-true-difference-between-a-dictionary-and-a-hash-table) (not mandatory).

## Tasks

### 0. >>> ht = {} - mandatory

Write a function that creates a hash table.

      * Prototype: hash_table_t *hash_table_create(unsigned long int size);

      * where size is the size of the array

      * Returns a pointer to the newly created hash table

      * If something went wrong, your function should return NULL

julien@ubuntu:~/0x1A. Hash tables$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 0-main.c 0-hash_table_create.c -o a

julien@ubuntu:~/0x1A. Hash tables$ ./a 

0x238a010

julien@ubuntu:~/0x1A. Hash tables$ valgrind ./a

==7602== Memcheck, a memory error detector

==7602== Copyright (C) 2002-2013, and GNU GPL'd, by Julian Seward et al.

==7602== Using Valgrind-3.10.1 and LibVEX; rerun with -h for copyright info

==7602== Command: ./a

==7602==

0x51fc040

==7602==

==7602== HEAP SUMMARY:

==7602==     in use at exit: 8,208 bytes in 2 blocks

==7602==   total heap usage: 2 allocs, 0 frees, 8,208 bytes allocated

==7602==

==7602== LEAK SUMMARY:

==7602==    definitely lost: 16 bytes in 1 blocks

==7602==    indirectly lost: 8,192 bytes in 1 blocks

==7602==      possibly lost: 0 bytes in 0 blocks

==7602==    still reachable: 0 bytes in 0 blocks

==7602==         suppressed: 0 bytes in 0 blocks

==7602== Rerun with --leak-check=full to see details of leaked memory

==7602==

==7602== For counts of detected and suppressed errors, rerun with: -v

==7602== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

### 1. djb2 -mandatory

Write a hash function implementing the djb2 algorithm.

      * Prototype: unsigned long int hash_djb2(const unsigned char *str);

      * You are allowed to copy and paste the function from this page

julien@ubuntu:~/0x1A. Hash tables$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 1-main.c 1-djb2.c -o b

julien@ubuntu:~/0x1A. Hash tables$ ./b

6953392314605

3749890792216096085

5861846

2. key -> index - mandatory

Write a function that gives you the index of a key.

      * Prototype: unsigned long int key_index(const unsigned char *key, unsigned long int size);

      	* where key is the key

	* and size is the size of the array of the hash table

      * This function should use the hash_djb2 function that you wrote earlier

      * Returns the index at which the key/value pair should be stored in the array of the hash table

      * You will have to use this hash function for all the next tasks

julien@ubuntu:~/0x1A. Hash tables$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 2-main.c 1-djb2.c 2-key_index.c -o c

julien@ubuntu:~/0x1A. Hash tables$ ./c

6953392314605

237

3749890792216096085

341

5861846

470

### 3. >>> ht['betty'] = 'cool' - mandatory

Write a function that adds an element to the hash table.

      * Prototype: int hash_table_set(hash_table_t *ht, const char *key, const char *value);

      	* Where ht is the hash table you want to add or update the key/value to
	* key is the key. key can not be an empty string

	* and value is the value associated with the key. value must be duplicated. value can be an empty string
      * Returns: 1 if it succeeded, 0 otherwise

      * In case of collision, add the new node at the beginning of the list

julien@ubuntu:~/0x1A. Hash tables$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 3-main.c 0-hash_table_create.c 1-djb2.c 2-key_index.c 3-hash_table_set.c -o d

If you want to test for collisions, here are some strings that collide using the djb2 algorithm:

   * **hetairas** collides with **mentioner**

   * **heliotropes** collides with **neurospora**

   * **depravement** collides with **serafins**

   * **stylist** collides with **subgenera**

   * **joyful** collides with **synaphea**

   * **redescribed** collides with **urites**

   * **dram** collides with **vivency**

###  >>> ht['betty'] - mandatory

Write a function that retrieves a value associated with a key.

      * Prototype: char *hash_table_get(const hash_table_t *ht, const char *key);

      	* where ht is the hash table you want to look into

	* and key is the key you are looking for

      * Returns the value associated with the element, or NULL if key couldn’t be found

julien@ubuntu:~/0x1A. Hash tables$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 4-main.c 0-hash_table_create.c 1-djb2.c 2-key_index.c 3-hash_table_set.c 4-hash_table_get.c -o e

julien@ubuntu:~/0x1A. Hash tables$ ./e

python:awesome

Bob:and Kris love asm

N:queens

Asterix:Obelix

Betty:Cool

98:Battery Street

c:isfun

javascript:(null)

