#include <queue>
#include <set>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	int minPushBox(vector<vector<char>> &grid)
	{
		int m = grid.size(), n = grid[0].size(), dsti, dstj, pi, pj, bi, bj;
		set<pair<int, int>> seen;
		queue<pair<int, int>> q;
		// get the position of box player and target
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (grid[i][j] == 'T')
				{
					dsti = i;
					dstj = j;
					grid[i][j] = '.';
				}
				else if (grid[i][j] == 'B')
				{
					bi = i;
					bj = j;
					grid[i][j] = '.';
				}
				else if (grid[i][j] == 'S')
				{
					pi = i;
					pj = j;
					grid[i][j] = '.';
				}
			}
		}

		q.push({bi * n + bj, pi * n + pj});
		int res = -1;
		while (!q.empty())
		{
			int size = q.size();
			++res;
			while (--size >= 0)
			{
				auto tmp = q.front();
				q.pop();
				int bx = tmp.first / n, by = tmp.first % n;
				int px = tmp.second / n, py = tmp.second % n;
				if (bx == dsti && by == dstj)
					return res;
				if (seen.find(tmp) != seen.end())
					continue;
				seen.insert(tmp);
				grid[bx][by] = 'B';
				if (bx - 1 >= 0 && bx + 1 < m && grid[bx - 1][by] == '.' && grid[bx + 1][by] == '.')
				{
					if (canMoveToPos(grid, px, py, bx + 1, by))
						q.push({(bx - 1) * n + by, bx * n + by});
					if (canMoveToPos(grid, px, py, bx - 1, by))
						q.push({(bx + 1) * n + by, bx * n + by});
				}
				if (by - 1 >= 0 && by + 1 < n && grid[bx][by - 1] == '.' && grid[bx][by + 1] == '.')
				{
					if (canMoveToPos(grid, px, py, bx, by + 1))
						q.push({bx * n + by - 1, bx * n + by});
					if (canMoveToPos(grid, px, py, bx, by - 1))
						q.push({bx * n + by + 1, bx * n + by});
				}
				grid[bx][by] = '.';
			}
		}
		return -1;
	}

	bool canMoveToPos(vector<vector<char>> &grid, int i, int j, int dsti, int dstj)
	{
		int m = grid.size(), n = grid[0].size();
		int direction[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
		if (i == dsti && j == dstj)
			return true;
		unordered_set<int> seen;
		queue<int> q;
		q.push(i * n + j);
		seen.insert(i * n + j);
		while (!q.empty())
		{
			int size = q.size();
			while (--size >= 0)
			{
				int tmp = q.front();
				q.pop();
				int x = tmp / n, y = tmp % n;
				for (int d = 0; d < 4; d++)
				{
					int dx = x + direction[d][0], dy = y + direction[d][1];
					if (dx < 0 || dx >= m || dy < 0 || dy >= n)
						continue;
					if (grid[dx][dy] == '#' || grid[dx][dy] == 'B')
						continue;
					if (seen.find(dx * n + dy) != seen.end())
						continue;
					if (dx == dsti && dy == dstj)
						return true;
					seen.insert(dx * n + dy);
					q.push(dx * n + dy);
				}
			}
		}
		return false;
	}
};