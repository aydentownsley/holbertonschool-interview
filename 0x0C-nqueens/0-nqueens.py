#!/usr/bin/python3
""" N Queens Problem """
import sys


def board_size():
    """gets board_board_size of board from user
    """
    if (len(sys.argv) != 2):
        print("Usage: nqueens N")
        sys.exit(1)
    try:
        n = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)
    if (n < 4):
        print("N must be at least 4")
        sys.exit(1)
    return n


def row_full(board, row):
    """checks if row is full
    """
    for full in board[row]:
        if (full == 1):
            return True
    return False


def col_full(board, col):
    """checks if col is full
    """
    board_size = len(board[0])
    for row in range(board_size):
        full = board[row][col]
        if full == 1:
            return True
    return False


def diag_full(board, row, col):
    """checks if diagonal is full
    """
    for x in range(row, -1, -1):
            if (board[x][x] == 1):
                return True
    return False

    for x in range(row, len(board), 1):
        for y in range(col, -1, -1):
            if (board[x][y] == 1):
                return True
    return False

def print_board(board, size):
    """ prints board """
    queens = [[i, j] for i in range(size) for j in range(size) if board[i][j] == 1]
    print(queens)

def n_queens():
    """ create chess board """
    size = board_size()
    board = [[0 for j in range(size)] for i in range(size)]
    solve_board(0, 0, board)


def solve_board(pos, queens, board):
    """ recurrrrrrsion """
    board_size = len(board[0])
    s = [(j, i) for j in range(board_size) for i in range(board_size)]
    if queens == board_size:
        print_board(board, board_size)
        return True
    elif pos >= len(s):
        return False
    i, j = s[pos]
    if not row_full(board, i) and not col_full(board, j) \
       and not diag_full(board, i, j):
        queens += 1
    b_true = [row[:] for row in board]
    b_false = [row[:] for row in board]
    b_true[i][j] = True
    b_false[i][j] = False
    if solve_board(pos + 1, queens, b_true) or \
       solve_board(pos + 1, queens, b_false):
        return True


if __name__ == "__main__":
	n_queens()
