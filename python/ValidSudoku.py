from typing import List


class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        sudoku = []
        for i, row in enumerate(board):
            for j, c in enumerate(row):
                if c != '.':
                    sudoku += ((i, c), (c, j), (i//3, j//3, c))
        return len(sudoku) == len(set(sudoku))
