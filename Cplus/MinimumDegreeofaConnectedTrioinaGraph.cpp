#include <climits>
#include <vector>
using namespace std;

class Solution
{
public:
	int minTrioDegree(int n, vector<vector<int>> &edges)
	{
		vector<int> degree(n + 1);
		vector<vector<int>> graph(n + 1, vector<int>(n + 1));
		for (auto &edge : edges)
		{
			++degree[edge[0]];
			++degree[edge[1]];
			graph[edge[0]][edge[1]] = 1;
			graph[edge[1]][edge[0]] = 1;
		}
		int res = INT_MAX;
		for (int i = 1; i < n - 1; ++i)
		{
			for (int j = i + 1; j < n; ++j)
			{
				for (int k = j + 1; k <= n; ++k)
				{
					if (graph[i][j] == 1 && graph[j][k] == 1 && graph[i][k] == 1)
						res = min(res, degree[i] + degree[j] + degree[k] - 6);
				}
			}
		}
		return res >= INT_MAX ? -1 : res;
	}
};