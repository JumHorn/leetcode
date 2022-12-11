#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> maxPoints(vector<vector<int>> &grid, vector<int> &queries)
	{
		vector<pair<int, int>> v; //{q,index}
		int k = queries.size(), M = grid.size(), N = grid[0].size();
		vector<int> res(k);
		for (int i = 0; i < k; ++i)
			v.push_back({queries[i], i});
		sort(v.begin(), v.end());
		int count = 0;
		// board dfs direction
		int path[5] = {-1, 0, 1, 0, -1};
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q; //{val,index}
		q.push({grid[0][0], 0});
		grid[0][0] = -1;
		for (auto t : v)
		{
			int val = t.first, index = t.second;
			while (!q.empty() && val > q.top().first)
			{
				int x = q.top().second / N, y = q.top().second % N;
				q.pop();
				++count;
				for (int i = 0; i < 4; ++i)
				{
					int dx = x + path[i], dy = y + path[i + 1];
					if (dx >= 0 && dx < M && dy >= 0 && dy < N && grid[dx][dy] != -1)
					{
						q.push({grid[dx][dy], dx * N + dy});
						grid[dx][dy] = -1;
					}
				}
			}
			res[index] = count;
		}
		return res;
	}
};