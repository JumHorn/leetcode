#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> highestRankedKItems(vector<vector<int>> &grid, vector<int> &pricing, vector<int> &start, int k)
	{
		int M = grid.size(), N = grid[0].size();
		auto f = [&](pair<int, int> &lhs, pair<int, int> &rhs)
		{
			if (lhs.second != rhs.second)
				return lhs.second < rhs.second;
			int r1 = lhs.first / N, c1 = lhs.first % N, r2 = rhs.first / N, c2 = rhs.first % N;
			if (r1 != r2)
				return r1 < r2;
			return c1 < c2;
		};
		vector<vector<int>> res;
		int lo = pricing[0], hi = pricing[1];
		int x = start[0], y = start[1];
		if (grid[x][y] >= lo && grid[x][y] <= hi)
			res.push_back({x, y});
		queue<int> q; //pos
		q.push(x * N + y);
		vector<vector<int>> seen(M, vector<int>(N));
		seen[x][y] = 1;
		while (!q.empty() && res.size() < k)
		{
			int size = q.size();
			vector<pair<int, int>> v; //{pos,price}
			while (--size >= 0)
			{
				int pos = q.front();
				q.pop();
				x = pos / N, y = pos % N;
				int path[] = {-1, 0, 1, 0, -1};
				for (int i = 0; i < 4; ++i)
				{
					int dx = x + path[i], dy = y + path[i + 1];
					if (dx >= 0 && dx < M && dy >= 0 && dy < N)
					{
						if (seen[dx][dy] != 0)
							continue;
						seen[dx][dy] = 1;
						if (grid[dx][dy] == 0)
							continue;
						if (grid[dx][dy] >= lo && grid[dx][dy] <= hi)
							v.push_back({dx * N + dy, grid[dx][dy]});
						q.push(dx * N + dy);
					}
				}
			}
			sort(v.begin(), v.end(), f);
			for (int i = 0; i < v.size() && res.size() < k; ++i)
			{
				x = v[i].first / N, y = v[i].first % N;
				res.push_back({x, y});
			}
		}
		return res;
	}
};