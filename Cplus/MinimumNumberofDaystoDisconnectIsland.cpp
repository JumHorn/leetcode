#include <vector>
using namespace std;

class Solution
{
public:
	int minDays(vector<vector<int>> &grid)
	{
		int M = grid.size(), N = grid[0].size();
		vector<vector<int>> graph(M * N, vector<int>(M * N));
		int start = -1, count = 0;
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (grid[i][j] == 0)
					continue;
				start = i * N + j;
				++count;
				int path[5] = {-1, 0, 1, 0, -1};
				for (int k = 0; k < 4; ++k)
				{
					int dx = i + path[k], dy = j + path[k + 1];
					if (dx < 0 || dx >= M || dy < 0 || dy >= N)
						continue;
					if (grid[dx][dy] == 0)
						continue;
					graph[i * N + j][dx * N + dy] = 1;
					graph[dx * N + dy][i * N + j] = 1;
				}
			}
		}
		if (start == -1)
			return 0;
		vector<int> dsc(M * N), low(M * N), seen(M * N);
		if (dfs(graph, start, seen) != count)
			return 0;
		if (count == 2)
			return 2;
		int time = 0;
		if (dfs(graph, start, dsc, low, time, -1))
			return 1;
		return 2;
	}

	bool dfs(vector<vector<int>> &graph, int at, vector<int> &dsc, vector<int> &low, int &time, int parent)
	{
		if (dsc[at] != 0)
			return false;
		dsc[at] = low[at] = ++time;
		for (int to = 0; to < (int)graph[at].size(); ++to)
		{
			if (graph[at][to] == 0)
				continue;
			if (dsc[to] == 0)
			{
				if (dfs(graph, to, dsc, low, time, at))
					return true;
				low[at] = min(low[at], low[to]);
				if (low[to] > dsc[at])
					return true;
			}
			else if (parent != to)
				low[at] = min(low[at], dsc[to]);
		}
		return false;
	}

	int dfs(vector<vector<int>> &graph, int at, vector<int> &seen)
	{
		if (seen[at] == 1)
			return 0;
		seen[at] = 1;
		int res = 1;
		for (int to = 0; to < (int)graph[at].size(); ++to)
		{
			if (graph[at][to] != 0)
				res += dfs(graph, to, seen);
		}
		return res;
	}
};