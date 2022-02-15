#!/usr/bin/python3
""" Island Perimeter Module """


def island_perimeter(grid):
    """ Finds perimeter of an island """
    p = 0
    for length in range(len(grid)):
        for w in range(len(grid[length])):
            if grid[length][w] == 1:
                if length != 0:
                    if not grid[length - 1][w]:
                        p += 1
                else:
                    p += 1
                if length != len(grid) - 1:
                    if not grid[length + 1][w]:
                        p += 1
                else:
                    p += 1
                if w != 0:
                    if not grid[length][w - 1]:
                        p += 1
                else:
                    p += 1
                if w != len(grid[length]) - 1:
                    if not grid[length][w + 1]:
                        p += 1
                else:
                    p += 1
    return p
