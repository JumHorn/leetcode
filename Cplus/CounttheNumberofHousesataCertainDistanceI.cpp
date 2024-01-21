#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> countOfPairs(int n, int x, int y)
	{
		vector<int> res(n);
		vector<vector<int>> graph(n + 1, vector<int>(n + 1, 1e9));
		for (int i = 1; i < n; ++i)
			graph[i][i + 1] = graph[i + 1][i] = 1;
		graph[x][y] = graph[y][x] = 1;
		for (int i = 0; i <= n; ++i)
			graph[i][i] = 0;
		// Floyd Algorithm
		for (int k = 0; k <= n; ++k)
			for (int i = 0; i <= n; ++i)
				for (int j = 0; j <= n; ++j)
					graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);

		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				if (graph[i][j] > 0)
					++res[graph[i][j] - 1];
			}
		}
		return res;
	}
};