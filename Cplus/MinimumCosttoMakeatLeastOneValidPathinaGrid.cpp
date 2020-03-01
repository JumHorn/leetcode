#include <climits>
#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
	int minCost(vector<vector<int>> &grid)
	{
		int m = grid.size(), n = grid[0].size();
		vector<vector<int>> seen(m, vector<int>(n));
		priority_queue<pair<int, int>> q;
		int res = 0;
		q.push({0, 0});
		while (!q.empty())
		{
			auto tmp = q.top();
			q.pop();
			int i = tmp.second / n, j = tmp.second % n;
			res = -tmp.first;
			if (seen[i][j] == 1)
				continue;
			if (i == m - 1 && j == n - 1)
				return res;
			seen[i][j] = 1;
			if (i - 1 >= 0)
				q.push({tmp.first - (grid[i][j] == 4 ? 0 : 1), (i - 1) * n + j});
			if (i + 1 < m)
				q.push({tmp.first - (grid[i][j] == 3 ? 0 : 1), (i + 1) * n + j});
			if (j - 1 >= 0)
				q.push({tmp.first - (grid[i][j] == 2 ? 0 : 1), i * n + j - 1});
			if (j + 1 < n)
				q.push({tmp.first - (grid[i][j] == 1 ? 0 : 1), i * n + j + 1});
		}
		return res;
	}
};