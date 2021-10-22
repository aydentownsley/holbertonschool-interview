#!/usr/bin/python3
""" N Queens Problem """
import sys


def solve(n):
    """ handles all solutions """
    board = create_board(n)
    add_queens(board)


def create_board(n):
    """ creates and empty chess board of size n """
    board = []
    row = []
    if isinstance(n, int):
        row = ["[ ]" for i in range(n)]
        board = [row.copy() for i in range(n)]
        return board


def add_queens(board, idx=0):
    """ adds queens to the board """
    next = idx + 1
    row = board[idx]
    for col in range(len(row)):
        row[col] = "Q"
        if is_valid(board):
            if next < len(board):
                add_queens(board, next)
            elif next == len(board):
                print_board(board)
        row[col] = "[ ]"


def is_valid(board):
    """ returns true if valid organization for queens """
    queens = []
    for row in range(len(board)):
        for col in range(len(board[row])):
            if board[row][col] == "Q":
                queens.append((row, col))

    for queen in queens:
        for other in queens:
            x1, y1 = queen[0], queen[1]
            x2, y2 = other[0], other[1]
            if x1 == x2 and y1 == y2:
                continue
            elif x1 == x2 or y1 == y2:
                return False
            elif (abs((x1 - x2) / (y1 - y2)) == 1):
                return False
    return True


def print_board(board):
    """ prints the board pos of valid organizations """
    queens = []
    for row in range(len(board)):
        for col in range(len(board[row])):
            if board[row][col] == "Q":
                queens.append([row, col])
    print(queens)


def start():
    if (len(sys.argv) < 2):
        print("Usage: nqueens N")
        sys.exit(1)
    n = sys.argv[1]
    if not n.isdigit():
        print("N must be a number")
        sys.exit(1)
    n = int(n)
    if n < 4:
        print("N must be at least 4")
        sys.exit(1)
    solve(n)


if __name__ == "__main__":
    start()
