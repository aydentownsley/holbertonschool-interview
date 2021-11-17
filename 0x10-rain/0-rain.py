#!/usr/bin/python3
""" Rain module """


def rain(walls):
    """ Determines max amount of rain
        that can be held in the walls

    Args:
        walls (List): list of height from 0 to n
    """
    # instantiate int vars and list vars
    area = neg_area = 0
    left_walls = right_walls = []

    # checks for empty list
    if len(walls) == 0:
        return 0

    # finds top 2 max values (and null check)
    copy_walls = walls[:]
    mx_0 = max(copy_walls)
    copy_walls.remove(mx_0)
    if len(copy_walls) == 0:
        return 0
    mx_1 = max(copy_walls)

    # determines which way to iterated in for loops
    if walls.index(mx_1) > walls.index(mx_0):
        l_idx = walls.index(mx_0)
        r_idx = walls.index(mx_1)
    else:
        l_idx = walls.index(mx_1)
        r_idx = walls.index(mx_0)

    # creates slices of lists for recursion
    left_walls = walls[0:l_idx + 1]
    right_walls = walls[r_idx:len(walls) - 1]

    # calculates area between walls and subtracts height of
    # walls in between
    if mx_0 > mx_1:
        for x in range(l_idx + 1, r_idx):
            neg_area -= walls[x]
            area = mx_1 * (r_idx - l_idx - 1)
            area -= neg_area
    else:
        for x in range(l_idx + 1, r_idx):
            neg_area -= walls[x]
            area = mx_0 * (r_idx - l_idx - 1)
            area -= neg_area

    # adds recursed area to area
    area += rain(left_walls)
    area += rain(right_walls)

    return area
