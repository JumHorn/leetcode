#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	int minFlips(vector<vector<int>> &mat)
	{
		unordered_set<int> seen;
		int M = mat.size(), N = mat[0].size(), matrix = 0;
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (mat[i][j] == 1)
					matrix = bitFlip(matrix, i * N + j);
			}
		}
		if (matrix == 0)
			return 0;
		queue<int> q;
		q.push(matrix);
		int res = 0;
		seen.insert(matrix);
		while (!q.empty())
		{
			int size = q.size();
			++res;
			while (--size >= 0)
			{
				int top = q.front();
				q.pop();
				for (int i = 0; i < M; ++i)
				{
					for (int j = 0; j < N; ++j)
					{
						int state = encodeFlip(top, M, N, i, j);
						if (state == 0)
							return res;
						if (seen.find(state) == seen.end())
						{
							seen.insert(state);
							q.push(state);
						}
					}
				}
			}
		}
		return -1;
	}

	int encodeFlip(int mat, int M, int N, int row, int col)
	{
		mat = bitFlip(mat, row * N + col);
		//board dfs direction
		int path[5] = {-1, 0, 1, 0, -1};
		for (int i = 0; i < 4; ++i)
		{
			int dx = row + path[i], dy = col + path[i + 1];
			if (dx >= 0 && dx < M && dy >= 0 && dy < N)
				mat = bitFlip(mat, dx * N + dy);
		}
		return mat;
	}

	int bitFlip(int num, int bit)
	{
		return num ^ (1 << bit);
	}
};