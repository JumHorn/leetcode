#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	int countServers(vector<vector<int>> &grid)
	{
		int servers = 0, M = grid.size(), N = grid[0].size();
		unordered_set<int> row, column;
		for (int i = 0; i < M; ++i)
		{
			int count = 0;
			for (int j = 0; j < N; ++j)
			{
				if (grid[i][j] == 1)
					++count;
			}
			if (count == 1)
				row.insert(i);
			servers += count;
		}
		for (int j = 0; j < N; ++j)
		{
			int count = 0;
			for (int i = 0; i < M; ++i)
			{
				if (grid[i][j] == 1)
					++count;
			}
			if (count == 1)
				column.insert(j);
		}
		for (auto r : row)
		{
			for (auto c : column)
				servers -= grid[r][c];
		}
		return servers;
	}
};