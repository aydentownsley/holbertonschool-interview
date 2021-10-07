#include "menger.h"

/**
 * menger - draws a 2D Menger sponge
 *
 * @level: level of the Menger sponge
 *
 * Return: void
 */
void menger(int level)
{
	int x = 0, y = 0, z = 0;
	bool print_hash = true;

	if (level < 0)
		return;

	if (level == 0)
	{
		printf("#\n");
		return;
	}

	for (x = 0; x < pow(3, level); ++x)
	{
		for (y = 0; y < pow(3, level); ++y)
		{
			print_hash = true;
			for (z = 0; z < level; ++z)
			{
				if ((x / (int)pow(3, z)) % 3 == 1 && (y / (int)pow(3, z)) % 3 == 1)
					print_hash = false;
			}

				if (print_hash)
					printf("#");
				else
					printf(" ");
		}
		printf("\n");
	}
}
