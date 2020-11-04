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
		int m = mat.size(), n = mat[0].size(), matrix = 0;
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (mat[i][j] == 1)
					matrix = bitFlip(matrix, i * n + j);
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
				for (int i = 0; i < m; ++i)
				{
					for (int j = 0; j < n; ++j)
					{
						int state = encodeFlip(top, m, n, i, j);
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

	int encodeFlip(int mat, int m, int n, int i, int j)
	{
		mat = bitFlip(mat, i * n + j);
		if (i - 1 >= 0)
			mat = bitFlip(mat, (i - 1) * n + j);
		if (i + 1 < m)
			mat = bitFlip(mat, (i + 1) * n + j);
		if (j - 1 >= 0)
			mat = bitFlip(mat, i * n + j - 1);
		if (j + 1 < n)
			mat = bitFlip(mat, i * n + j + 1);
		return mat;
	}

	int bitFlip(int num, int bit)
	{
		return num ^ (1 << bit);
	}
};