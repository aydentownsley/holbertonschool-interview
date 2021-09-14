#include <stdlib.h>
#include <stdio.h>
#include "palindrome.h"

/**
 * is_palindrome - checks if an int is a palindrome
 *
 * @n: long unsigned int
 *
 * Return: 1 if palindrome
 * 0 if not
 */

int is_palindrome(unsigned long n)
{
	unsigned long int rev = 0, n2 = 0, mod = 0;
	n2 = n;

	while (n2 != 0)
	{
		mod = n2 % 10;
		rev = rev * 10 + mod;
		n2 /= 10;
	}

	if (n == rev)
		return (1);

	return (0);
}
