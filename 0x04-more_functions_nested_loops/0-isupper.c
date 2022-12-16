#include "main.h"

/**
 * _isupper - checks for upper case latter
 * @c: character to check
 *
 * Return: 0 or 1
 */

int _isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}
