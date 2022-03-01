#include "holberton.h"

/**
 * valid - checks if wildcard is valid
 *
 * @s1: string to compare
 * @s2: wildcard to validate
 * @c1: first spot checked
 * @c2: first spot in comparison
 *
 * Return: spot that matches or NULL
 */
char *valid(char *s1, char *s2, char *c1, char *c2)
{
	if (*s2 == '*' || (*s1 == '\0' && *s2 == '\0'))
		return (c1);
	else if (*s1 != *s2)
		return (check(s1, c2));
	else
		return (valid(s1 + 1, s2 + 1, c1, c2));
}

/**
 * check - reviews non end wildcards
 *
 * @s1: string to compare
 * @s2: string to check
 *
 * Return: place where s1 goes back to matching s2
 */
char *check(char *s1, char *s2)
{
	if (*s1 != *s2)
	{
		if (*s1 == '\0')
			return (0);

		return (check(s1 + 1, s2));
	}

	return (valid(s1 + 1, s2 + 1, s1, s2));
}

/**
 * wildcmp - compares two strings
 *
 * @s1: pointer to string 1
 * @s2: pointer to string 2
 *
 * Return: 1 if MATCH, 0 if NO
 */

int wildcmp(char *s1, char *s2)
{
	char *i;

	/**
	* first if: last char of s2 is * then they match
	* second if: if mult * in a row keep iteratign until they dont
	* third if: if * not at end need to check what comes next
	* fourth if: if s1 and s2 char are not * and dont match not identical
	*/
	if (*s2 == '*' && *(s2 + 1) == '\0')
		return (1);
	else if (*s2 == '*' && *(s2 + 1) == '*')
		return (wildcmp(s1, s2 + 1));
	else if (*s2 == '*')
	{
		i = check(s1, s2 + 1);

		if (i == 0)
			return (0);

		return (wildcmp(i + 1, s2 + 2));
	}
	else if (*s1 != *s2)
		return (0);

	/* if both strings get past all that then they match if they both end */
	if (*s1 == '\0' && *s2 == '\0')
		return (1);

	/* bump one down if they do not end */
	return (wildcmp(s1 + 1, s2 + 1));
}
