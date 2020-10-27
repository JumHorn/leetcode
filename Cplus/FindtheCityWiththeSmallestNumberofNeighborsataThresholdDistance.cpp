#include <algorithm>
#include <climits>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
	{
		vector<vector<int>> graph(n, vector<int>(n, 1e9));
		for (auto &edge : edges)
		{
			graph[edge[0]][edge[1]] = edge[2];
			graph[edge[1]][edge[0]] = edge[2];
		}
		for (int i = 0; i < n; ++i)
			graph[i][i] = 0;
		//Floyd Algorithm
		for (int k = 0; k < n; ++k)
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < n; ++j)
					graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);

		int res = -1, mincount = INT_MAX;
		for (int i = n - 1; i >= 0; --i)
		{
			int count = 0;
			for (int j = 0; j < n; ++j)
			{
				if (graph[i][j] <= distanceThreshold)
					++count;
			}
			if (count < mincount)
			{
				mincount = count;
				res = i;
			}
		}
		return res;
	}
};