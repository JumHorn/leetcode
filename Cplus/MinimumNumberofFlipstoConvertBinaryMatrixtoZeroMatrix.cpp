#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	int minFlips(vector<vector<int>>& mat)
	{
		unordered_set<int> visited;
		int m = mat.size(), n = mat[0].size(), matrix = 0;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				if (mat[i][j] == 1)
					matrix = bitReverse(matrix, i * n + j);
		if (matrix == 0)
			return 0;
		queue<int> q;
		q.push(matrix);
		int res = 0;
		visited.insert(matrix);
		while (!q.empty())
		{
			int size = q.size();
			++res;
			while (--size >= 0)
			{
				int top = q.front();
				q.pop();
				for (int i = 0; i < m; i++)
					for (int j = 0; j < n; j++)
					{
						int tmp = encodeFlip(top, m, n, i, j);
						if (tmp == 0)
							return res;
						if (visited.find(tmp) == visited.end())
						{
							visited.insert(tmp);
							q.push(tmp);
						}
					}
			}
		}
		return -1;
	}

	int encodeFlip(int mat, int m, int n, int i, int j)
	{
		mat = bitReverse(mat, i * n + j);
		if (i - 1 >= 0)
			mat = bitReverse(mat, (i - 1) * n + j);
		if (i + 1 < m)
			mat = bitReverse(mat, (i + 1) * n + j);
		if (j - 1 >= 0)
			mat = bitReverse(mat, i * n + j - 1);
		if (j + 1 < n)
			mat = bitReverse(mat, i * n + j + 1);
		return mat;
	}

	int bitReverse(int num, int bit)
	{
		return ((~num) & (1u << bit)) | (num & (~(1u << bit)));
	}
};