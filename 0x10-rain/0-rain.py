#!/usr/bin/python3
""" Rain module """


def rain(walls):
    """ Determines max amount of rain
        that can be held in the walls

    Args:
        walls (List): list of height from 0 to n
    """
    # instantiate int vars and list vars
    area = neg_area = mx_0 = mx_1 = 0
    left_walls = right_walls = []

    # checks for empty list or list not worth checking
    if len(walls) <= 2:
        return 0

    # finds top 2 max values and index of mx_1
    mx_0 = max(walls)
    for i in range(len(walls)):
        if i != walls.index(mx_0) and mx_1 < walls[i]:
            mx_1 = walls[i]
            index_mx_1 = i

    if mx_0 == 0 or mx_1 == 0:
        return 0

    # determines which way to iterate in for loops
    if index_mx_1 > walls.index(mx_0):
        l_idx = walls.index(mx_0)
        r_idx = index_mx_1
    else:
        l_idx = index_mx_1
        r_idx = walls.index(mx_0)

	 # creates slices of lists for recursion
    left_walls = walls[0:l_idx + 1]
    right_walls = walls[r_idx:len(walls)]

    # calculates area between walls and subtracts height of
    # walls in between
    if mx_0 >= mx_1:
        for x in range(l_idx + 1, r_idx):
            neg_area -= walls[x]
        area = mx_1 * (r_idx - l_idx - 1)
        area += neg_area
    else:
        for x in range(l_idx + 1, r_idx):
            neg_area -= walls[x]
        area = mx_0 * (r_idx - l_idx - 1)
        area += neg_area

    # adds recursed area to area
    area += rain(left_walls)
    area += rain(right_walls)

    return area
