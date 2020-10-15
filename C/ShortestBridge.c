#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

void dfs(int **A, int M, int N, int row, int col, int (*islandEdge)[2], int *islandEdgeSize)
{
	if (row < 0 || row >= M || col < 0 || col >= N || A[row][col] == 2)
		return;
	if (A[row][col] == 0)
	{
		islandEdge[*islandEdgeSize][0] = row;
		islandEdge[*islandEdgeSize][1] = col;
		++*islandEdgeSize;
		return;
	}
	A[row][col] = 2; //0 water 1 island 2 visited
	//board dfs direction
	int path[5] = {-1, 0, 1, 0, -1};
	for (int i = 0; i < 4; ++i)
		dfs(A, M, N, row + path[i], col + path[i + 1], islandEdge, islandEdgeSize);
}

int shortestBridge(int **A, int ASize, int *AColSize)
{
	bool firstIslandFound = false;
	int islandEdgeSize = 0, islandEdge[ASize * ASize][2]; //{row,col}
	int res = INT_MAX;
	for (int i = 0; i < ASize; ++i)
	{
		for (int j = 0; j < *AColSize; ++j)
		{
			if (A[i][j] == 1)
			{
				if (firstIslandFound)
				{
					for (int k = 0; k < islandEdgeSize; ++k)
						res = min(res, abs(islandEdge[k][0] - i) + abs(islandEdge[k][1] - j));
				}
				else
				{
					firstIslandFound = true;
					dfs(A, ASize, *AColSize, i, j, islandEdge, &islandEdgeSize);
				}
			}
		}
	}
	return res;
}