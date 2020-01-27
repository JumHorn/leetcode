#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold)
	{
		vector<vector<int>> graph(n, vector<int>(n, 1e9));
		for (int i = 0; i < (int)edges.size(); i++)
		{
			graph[edges[i][0]][edges[i][1]] = edges[i][2];
			graph[edges[i][1]][edges[i][0]] = edges[i][2];
		}
		for (int i = 0; i < n; i++)
			graph[i][i] = 0;
		for (int k = 0; k < n; k++)
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
		int res = -1, count = INT_MAX;
		for (int i = n - 1; i >= 0; i--)
		{
			int tmp = 0;
			for (int j = 0; j < n; j++)
				if (graph[i][j] <= distanceThreshold)
					tmp++;
			if (tmp < count)
			{
				count = tmp;
				res = i;
			}
		}
		return res;
	}
};
