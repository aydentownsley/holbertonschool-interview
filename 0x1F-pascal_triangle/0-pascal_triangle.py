#!/usr/bin/python3
"""
	Pascal's Triangle Module
"""


def pascal_triangle(n):
	"""
		n: size of triangle to create
	"""

	# define triangle array and "tip" of triangle
	triangle =[]
	row = [1]

	for i in range(n):
		triangle.append(row)
		next_row = []
		next_row.append(row[0])
		for i in range(len(row) - 1):
			next_row.append(row[i] + row[i+1])
		next_row.append(row[0])
		row = next_row
	return triangle
