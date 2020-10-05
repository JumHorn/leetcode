#include <algorithm>
#include <numeric>
#include <queue>
using namespace std;

class Solution
{
public:
	int networkDelayTime(vector<vector<int>> &times, int N, int K)
	{
		vector<int> dist(N + 1, INT_MAX);
		dist[K] = 0;
		for (int i = 0; i < N; ++i)
		{
			for (auto &t : times)
			{
				int u = t[0], v = t[1], w = t[2];
				if (dist[u] != INT_MAX && dist[v] > dist[u] + w)
					dist[v] = dist[u] + w;
			}
		}

		int res = *max_element(dist.begin() + 1, dist.end());
		return res == INT_MAX ? -1 : res;
	}
};