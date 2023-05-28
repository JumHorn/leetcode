#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> differenceOfDistinctValues(vector<vector<int>> &grid)
	{
		int M = grid.size(), N = grid[0].size();
		vector<vector<int>> res(M, vector<int>(N));
		unordered_map<int, unordered_set<int>> count, count1; //{i-j,distinct nums}
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				res[i][j] = count[i - j].size();
				count[i - j].insert(grid[i][j]);
			}
		}

		for (int i = M - 1; i >= 0; --i)
		{
			for (int j = N - 1; j >= 0; --j)
			{
				res[i][j] = abs(res[i][j] - (int)count1[i - j].size());
				count1[i - j].insert(grid[i][j]);
			}
		}
		return res;
	}
};