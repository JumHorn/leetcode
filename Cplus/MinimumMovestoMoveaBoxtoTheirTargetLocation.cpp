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
		int M = grid.size(), N = grid[0].size(), dsti, dstj, pi, pj, bi, bj;
		set<pair<int, int>> seen;
		queue<pair<int, int>> q; //{box position,player postion}
		// get the position of box player and target
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
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

		q.push({bi * N + bj, pi * N + pj});
		int res = -1;
		while (!q.empty())
		{
			++res;
			int size = q.size();
			while (--size >= 0)
			{
				auto state = q.front();
				q.pop();
				int bx = state.first / N, by = state.first % N;
				int px = state.second / N, py = state.second % N;
				if (bx == dsti && by == dstj)
					return res;
				if (seen.find(state) != seen.end())
					continue;
				seen.insert(state);
				grid[bx][by] = 'B';
				if (bx - 1 >= 0 && bx + 1 < M && grid[bx - 1][by] == '.' && grid[bx + 1][by] == '.')
				{
					if (canMoveToPos(grid, px, py, bx + 1, by))
						q.push({(bx - 1) * N + by, bx * N + by});
					if (canMoveToPos(grid, px, py, bx - 1, by))
						q.push({(bx + 1) * N + by, bx * N + by});
				}
				if (by - 1 >= 0 && by + 1 < N && grid[bx][by - 1] == '.' && grid[bx][by + 1] == '.')
				{
					if (canMoveToPos(grid, px, py, bx, by + 1))
						q.push({bx * N + by - 1, bx * N + by});
					if (canMoveToPos(grid, px, py, bx, by - 1))
						q.push({bx * N + by + 1, bx * N + by});
				}
				grid[bx][by] = '.';
			}
		}
		return -1;
	}

	bool canMoveToPos(vector<vector<char>> &grid, int row, int col, int dsti, int dstj)
	{
		int M = grid.size(), N = grid[0].size();
		//board dfs direction
		int path[5] = {-1, 0, 1, 0, -1};
		if (row == dsti && col == dstj)
			return true;
		unordered_set<int> seen;
		queue<int> q;
		q.push(row * N + col);
		seen.insert(row * N + col);
		while (!q.empty())
		{
			int size = q.size();
			while (--size >= 0)
			{
				int state = q.front();
				q.pop();
				int x = state / N, y = state % N;
				for (int d = 0; d < 4; ++d)
				{
					int dx = x + path[d], dy = y + path[d + 1];
					if (dx < 0 || dx >= M || dy < 0 || dy >= N)
						continue;
					if (grid[dx][dy] == '#' || grid[dx][dy] == 'B')
						continue;
					if (seen.find(dx * N + dy) != seen.end())
						continue;
					if (dx == dsti && dy == dstj)
						return true;
					seen.insert(dx * N + dy);
					q.push(dx * N + dy);
				}
			}
		}
		return false;
	}
};