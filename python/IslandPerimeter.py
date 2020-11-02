from typing import List


class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        M, N = len(grid), len(grid[0])
        islands, neighbours = 0, 0
        for i in range(M):
            for j in range(N):
                if grid[i][j] == 1:
                    islands += 1
                    if i < M - 1 and grid[i + 1][j] == 1:
                        neighbours += 1
                    if j < N - 1 and grid[i][j + 1] == 1:
                        neighbours += 1
        return islands * 4 - neighbours * 2
