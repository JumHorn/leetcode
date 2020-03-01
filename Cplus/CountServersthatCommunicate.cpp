#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	int countServers(vector<vector<int>>& grid)
	{
		int sum = 0, m = grid.size(), n = grid[0].size();
		unordered_set<int> row, column;
		for (int i = 0; i < m; i++)
		{
			int count = 0;
			for (int j = 0; j < n; j++)
			{
				if (grid[i][j] == 1)
					count++;
			}
			if (count == 1)
				row.insert(i);
			sum += count;
		}
		for (int j = 0; j < n; j++)
		{
			int count = 0;
			for (int i = 0; i < m; i++)
				if (grid[i][j] == 1)
					count++;
			if (count == 1)
				column.insert(j);
		}
		for (auto rowiter : row)
			for (auto coliter : column)
				sum -= grid[rowiter][coliter];
		return sum;
	}
};
