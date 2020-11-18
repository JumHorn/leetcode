#include <queue>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	int shortestPathAllKeys(vector<string> &grid)
	{
		queue<pair<string, int>> q; //{keys in hand,position}
		int res = -1, M = grid.size(), N = grid[0].length();
		vector<unordered_set<string>> seen(M * N);
		string target = "......";
		auto start = findStartAndTarget(grid, target);
		q.push({"......", start.first * N + start.second});
		seen[start.first * N + start.second].insert("......");
		while (!q.empty())
		{
			++res;
			int size = q.size();
			while (--size >= 0)
			{
				auto state = q.front();
				q.pop();
				if (state.first == target)
					return res;
				int x = state.second / N, y = state.second % N;
				//board dfs direction
				int path[5] = {-1, 0, 1, 0, -1};
				for (int i = 0; i < 4; ++i)
				{
					int dx = x + path[i], dy = y + path[i + 1];
					if (dx < 0 || dx >= M || dy < 0 || dy >= N || grid[dx][dy] == '#')
						continue;
					string str = state.first;
					if (grid[dx][dy] >= 'A' && grid[dx][dy] <= 'F' && str[grid[dx][dy] - 'A'] == '.')
						continue;
					if (grid[dx][dy] >= 'a' && grid[dx][dy] <= 'f')
						str[grid[dx][dy] - 'a'] = grid[dx][dy];
					if (seen[dx * N + dy].find(str) != seen[dx * N + dy].end())
						continue;
					seen[dx * N + dy].insert(str);
					q.push({str, dx * N + dy});
				}
			}
		}
		return -1;
	}

	pair<int, int> findStartAndTarget(vector<string> &grid, string &target)
	{
		pair<int, int> res = {0, 0};
		for (int i = 0; i < (int)grid.size(); ++i)
		{
			for (int j = 0; j < (int)grid[i].length(); ++j)
			{
				if (grid[i][j] == '@')
					res = {i, j};
				else if (grid[i][j] >= 'a' && grid[i][j] <= 'f')
					target[grid[i][j] - 'a'] = grid[i][j];
			}
		}
		return res;
	}
};