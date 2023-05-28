#include <map>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxIncreasingCells(vector<vector<int>> &matrix)
	{
		int M = matrix.size(), N = matrix[0].size(), res = 0;
		map<int, vector<pair<int, int>>> m; //{val,(i,j)}
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
				m[matrix[i][j]].push_back({i, j});
		}
		vector<int> rowMax(M), colMax(N);
		for (auto &[val, index] : m)
		{
			vector<int> mx;
			for (auto [i, j] : index)
			{
				mx.push_back(max(rowMax[i], colMax[j]) + 1);
				res = max(res, mx.back());
			}
			for (int k = 0; k < index.size(); ++k)
			{
				auto [i, j] = index[k];
				rowMax[i] = max(rowMax[i], mx[k]);
				colMax[j] = max(colMax[j], mx[k]);
			}
		}
		return res;
	}
};