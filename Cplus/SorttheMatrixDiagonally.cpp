#include <algorithm>
#include <functional>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> diagonalSort(vector<vector<int>> &mat)
	{
		unordered_map<int, priority_queue<int, vector<int>, greater<int>>> m;
		int M = mat.size(), N = mat[0].size();
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
				m[i - j].push(mat[i][j]);
		}
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				mat[i][j] = m[i - j].top();
				m[i - j].pop();
			}
		}
		return mat;
	}
};