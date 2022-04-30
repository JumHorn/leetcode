#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
	int maximumMinutes(vector<vector<int>> &grid)
	{
		int M = grid.size(), N = grid[0].size();
		queue<int> q;
		//set wall to -1
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (grid[i][j] == 2)
					grid[i][j] = -1;
				else if (grid[i][j] == 1)
					q.push(i * N + j);
			}
		}

		//board dfs direction
		int path[5] = {-1, 0, 1, 0, -1};
		//bfs to set fire time
		int time = 1;
		while (!q.empty())
		{
			int size = q.size();
			++time;
			while (--size >= 0)
			{
				int x = q.front() / N, y = q.front() % N;
				q.pop();
				for (int i = 0; i < 4; ++i)
				{
					int dx = x + path[i], dy = y + path[i + 1];
					if (dx < 0 || dx >= M || dy < 0 || dy >= N)
						continue;
					if (grid[dx][dy] == 0) //grass
					{
						grid[dx][dy] = time;
						q.push(dx * N + dy);
					}
				}
			}
		}

		int lo = 0, hi = 1e5;
		vector<vector<int>> seen(M, vector<int>(N));
		while (lo < hi)
		{
			int mi = (hi - lo) / 2 + lo;
			for (auto &v : seen)
				fill(v.begin(), v.end(), 0);
			if (canReach(grid, mi, seen))
				lo = mi + 1;
			else
				hi = mi;
		}
		if (lo >= M * N)
			return 1e9;
		return lo - 1;
	}

	//bfs
	bool canReach(vector<vector<int>> &grid, int time, vector<vector<int>> &seen)
	{
		//board dfs direction
		int path[5] = {-1, 0, 1, 0, -1};
		int M = grid.size(), N = grid[0].size();
		queue<int> q;
		seen[0][0] = 1;
		q.push(0);
		int t = time + 1;
		while (!q.empty())
		{
			int size = q.size();
			++t;
			while (--size >= 0)
			{
				int x = q.front() / N, y = q.front() % N;
				q.pop();
				for (int i = 0; i < 4; ++i)
				{
					int dx = x + path[i], dy = y + path[i + 1];
					if (dx < 0 || dx >= M || dy < 0 || dy >= N)
						continue;
					if ((dx == M - 1 && dy == N - 1) && (grid[dx][dy] == 0 || t <= grid[dx][dy]))
						return true;
					if ((grid[dx][dy] == 0 || t < grid[dx][dy]) && seen[dx][dy] == 0)
					{
						seen[dx][dy] = 1;
						q.push(dx * N + dy);
					}
				}
			}
		}
		return false;
	}
};