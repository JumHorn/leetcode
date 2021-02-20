#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> highestPeak(vector<vector<int>> &isWater)
	{
		int M = isWater.size(), N = isWater[0].size();
		vector<vector<int>> res(M, vector<int>(N, -1));
		queue<pair<int, int>> q;
		for (int i = 0; i < M; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (isWater[i][j] == 1)
				{
					res[i][j] = 0;
					q.push({i, j});
				}
			}
		}
		int tag = 0;
		while (!q.empty())
		{
			int size = q.size();
			++tag;
			while (--size >= 0)
			{
				int path[] = {-1, 0, 1, 0, -1};
				auto pos = q.front();
				q.pop();
				int i = pos.first, j = pos.second;
				for (int k = 0; k < 4; ++k)
				{
					int x = i + path[k], y = j + path[k + 1];
					if (x < 0 || x >= M || y < 0 || y >= N)
						continue;
					if (res[x][y] != -1)
						continue;
					res[x][y] = tag;
					q.push({x, y});
				}
			}
		}

		return res;
	}
};