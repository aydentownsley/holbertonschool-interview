#!/usr/bin/python3
"""
2D Matrix Rotation Module
"""


def rotate_2d_matrix(matrix):
    """
    matrix: given 2D matrix

    return: none, matrix must be roateted in place
    """
    h = len(matrix)
    for x in range(h // 2):
        for y in range(x, h - x - 1):
            temp = matrix[x][y]
            matrix[x][y] = matrix[h - 1 - y][x]
            matrix[h - 1 - y][x] = matrix[h - 1 - x][h - 1 - y]
            matrix[h - 1 - x][h - 1 - y] = matrix[y][h - 1 - x]
            matrix[y][h - 1 - x] = temp
