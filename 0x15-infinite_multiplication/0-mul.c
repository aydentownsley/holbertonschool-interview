#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int _putchar(char c);
void pr(char to_print[]);
int checkInt(int *num);

/**
 * main - handles input and mult
 *
 * @argc: lenght of input
 * @argv: array of input
 *
 * Return: 98 if error
 * final mult string if successful
 */
int main(int argc, char *argv[])
{
	int a[5000], b[5000];
	int ans[100001] = {0};
	int i, j, tmp, l1, l2;

	if (argc != 3)
	{
		pr("Error\n");
		exit(98);
	}

	if (argv == NULL)
	{
		pr("Error\n");
		exit(98);
	}

	if (checkInt(a) || checkInt(b))
	{
		pr("Error\n");
		exit(98);
	}

	l1 = strlen(argv[1]);
	l2 = strlen(argv[2]);

	for (i = l1 - 1, j = 0; i >= 0; i--, j++)
	{
		a[j] = argv[1][i] - '0';
	}
	for (i = l2 - 1, j = 0; i >= 0; i--, j++)
	{
		b[j] = argv[2][i] - '0';
	}
	for (i = 0; i < l2; i++)
	{
		for (j = 0; j < l1 ; j++)
		{
			ans[i + j] += b[i] * a[j];
		}
	}
	for (i = 0; i < l1 + l2; i++)
	{
		tmp = ans[i] / 10;
		ans[i] = ans[i] % 10;
		ans[i + 1] = ans[i + 1] + tmp;
	}
	for (i = l1 + l2; i >= 0; i--)
	{
		if (ans[i] > 0)
			break;
	}

	for (; i >= 0; i--)
	{
		_putchar(ans[i] + '0');
	}
	_putchar(10);
	exit(0);
}

/**
 * pr - prints a string
 *
 * @to_print: char array to print
 *
 * Return: void
 */
void pr(char to_print[])
{
	int i = 0;

	while (to_print[i] != '\0')
	{
		_putchar(to_print[i]);
		++i;
	}
}

/**
 * checkInt - check int array for non int values
 *
 * @num: array to be checked
 *
 * Return: -1 if not a true int
 */
int checkInt(int *num)
{
	int i = 0;

	while (num[i] != '\0')
	{
		if (num[i] <= 47 || num[i] >= 57)
			return (-1);
	}

	return (0);
}
