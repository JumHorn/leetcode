#include <vector>
using namespace std;

class Solution
{
public:
	int maximumDetonation(vector<vector<int>> &bombs)
	{
		int N = bombs.size();
		vector<vector<int>> graph(N); //directed graph
		for (int i = 0; i < N; ++i)
		{
			int ai = bombs[i][0], bi = bombs[i][1], ri = bombs[i][2];
			for (int j = i + 1; j < N; ++j)
			{
				int aj = bombs[j][0], bj = bombs[j][1], rj = bombs[j][2];
				if (pointInCircle(ai, bi, ri, aj, bj))
					graph[i].push_back(j);
				if (pointInCircle(aj, bj, rj, ai, bi))
					graph[j].push_back(i);
			}
		}
		int res = 0;
		for (int i = 0; i < N; ++i)
		{
			vector<int> seen(N);
			res = max(res, dfs(graph, i, seen));
		}
		return res;
	}

	int dfs(vector<vector<int>> &graph, int at, vector<int> &seen)
	{
		if (seen[at] != 0)
			return 0;
		seen[at] = 1;
		int res = 1;
		for (auto to : graph[at])
			res += dfs(graph, to, seen);
		return res;
	}

	bool pointInCircle(int a, int b, int r, int x, int y)
	{
		return long(x - a) * (x - a) + long(y - b) * (y - b) <= (long)r * r;
	}
};