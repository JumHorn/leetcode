#include <cmath>
#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
	int shortestBridge(vector<vector<int>> &A)
	{
		int M = A.size(), N = A[0].size();
		queue<pair<int, int>> islandEdge;
		findLandEdge(A, islandEdge);
		//BFS
		int res = 0;
		while (!islandEdge.empty())
		{
			++res;
			int size = islandEdge.size();
			while (--size >= 0)
			{
				int row = islandEdge.front().first, col = islandEdge.front().second;
				islandEdge.pop();
				int path[5] = {-1, 0, 1, 0, -1};
				for (int i = 0; i < 4; ++i)
				{
					int dx = row + path[i], dy = col + path[i + 1];
					if (dx < 0 || dx >= M || dy < 0 || dy >= N || A[dx][dy] == 2)
						continue;
					if (A[dx][dy] == 1)
						return res;
					A[dx][dy] = 2;
					islandEdge.push({dx, dy});
				}
			}
		}
		return -1;
	}

	void findLandEdge(vector<vector<int>> &A, queue<pair<int, int>> &islandEdge)
	{
		int M = A.size(), N = A[0].size();
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (A[i][j] == 1)
				{
					dfs(A, i, j, islandEdge);
					return;
				}
			}
		}
	}

	void dfs(vector<vector<int>> &A, int row, int col, queue<pair<int, int>> &islandEdge)
	{
		int M = A.size(), N = A[0].size();
		if (row < 0 || row >= M || col < 0 || col >= N || A[row][col] == 2)
			return;
		if (A[row][col] == 0)
		{
			islandEdge.push({row, col});
			return;
		}
		A[row][col] = 2; //0 water 1 island 2 visited
		//board dfs direction
		int path[5] = {-1, 0, 1, 0, -1};
		for (int i = 0; i < 4; ++i)
			dfs(A, row + path[i], col + path[i + 1], islandEdge);
	}
};