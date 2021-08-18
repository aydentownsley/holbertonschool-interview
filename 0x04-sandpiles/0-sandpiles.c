#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include "sandpiles.h"

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
static void print_grid(int grid[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (j)
                printf(" ");
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
}

/**
 * stable - checks stability of sandpile
 *
 * @grid1: sandpile to check
 *
 * Return: True if stable
 * False if not
 */
bool stable(int grid1[3][3])
{
    int x, y;

    for (x = 0; x < 3; x++)
    {
        for (y = 0; y < 3; y++)
        {
            if (grid1[x][y] > 3)
                return (false);
        }
    }
    return (true);
}

/**
 * sandpiles_sum - returns a stable sum of two sandpile
 *
 * @grid1: Right 3x3
 * @grid2: Left 3x3
 *
 * Return: stable grid1 sum
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
    int x, y, a, b, c, d;

    for (x = 0; x < 3; x++)
    {
        for (y = 0; y < 3; y++)
        {
            grid1[x][y] += grid2[x][y];
        }
    }


    while (stable(grid1) == false)
    {
        printf("=\n");
        print_grid(grid1);

        for (x = 0; x < 3; x++)
        {
            for (y = 0; y < 3; y++)
            {
                if (grid1[x][y] > 3)
                {
                    a = x + 1;
                    b = x - 1;
                    c = y + 1;
                    d = y - 1;
                    grid1[x][y] -= 4;
                    if (a >= 0 && a <= 2)
                        grid1[a][y] += 1;
                    if (b >= 0 && b <= 2)
                        grid1[b][y] += 1;
                    if (c >= 0 && c <= 2)
                        grid1[x][c] += 1;
                    if (d >= 0 && d <= 2)
                        grid1[x][d] += 1;
                }
            }
        }
    }
}
