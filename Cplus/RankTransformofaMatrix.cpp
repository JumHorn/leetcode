#include <climits>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> matrixRankTransform(vector<vector<int>> &matrix)
	{
		int M = matrix.size(), N = matrix[0].size();
		vector<vector<int>> res(M, vector<int>(N));
		priority_queue<pair<int, int>> q; //{value,pos}
		int rank = 1;
		unordered_set<int> index;
		for (int i = 0; i < M; ++i)
		{
			index.clear();
			int k = 0;
			index.insert(k);
			for (int j = 1; j < N; ++j)
			{
				if (matrix[i][j] == matrix[i][k])
					index.insert(j);
				else if (matrix[i][j] < matrix[i][k])
				{
					k = j;
					index.clear();
					index.insert(k);
				}
			}
			for (auto c : index)
			{
				k = 0;
				for (; k < M; ++k)
				{
					if (matrix[i][c] > matrix[k][c])
						break;
				}
				if (k == M)
					res[i][c] = 1;
			}
		}
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (res[i][j] == 0)
				{
					q.push({-matrix[i][j], i * N + j});
				}
			}
		}
		int pre = INT_MIN;
		while (!q.empty())
		{
			int x = q.top().second / N, y = q.top().second % N;
			int value = -q.top().first;
			q.pop();
			if (value > pre)
			{
				res[x][y] = ++rank;
				pre = value;
			}
			else
				res[x][y] = rank;
		}
		return res;
	}
};