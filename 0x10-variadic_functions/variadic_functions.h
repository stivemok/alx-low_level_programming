#ifndef VARIADIC_FNS
#define VARIADIC_FNS

#include <stdarg.h>
/**
 * struct validTypes - key for pik
 * @f: ...
 * @valid: ...
 */
typedef struct validTypes
{
	char *valid;
	void (*f)();
} v_types;

int _putchar(char c);
int sum_them_all(const unsigned int n, ...);
void print_numbers(const char *separator, const unsigned int n, ...);
void print_strings(const char *separator, const unsigned int n, ...);
void print_all(const char * const format, ...);

#endif
