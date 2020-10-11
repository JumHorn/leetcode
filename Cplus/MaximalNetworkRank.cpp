#include <vector>
using namespace std;

class Solution
{
public:
	int maximalNetworkRank(int n, vector<vector<int>> &roads)
	{
		vector<vector<int>> graph(n, vector<int>(n));
		vector<int> indegree(n);
		for (auto &road : roads)
		{
			graph[road[0]][road[1]] = graph[road[1]][road[0]] = 1;
			++indegree[road[0]];
			++indegree[road[1]];
		}
		int res = 0;
		for (int i = 0; i < n - 1; ++i)
		{
			for (int j = i + 1; j < n; ++j)
				res = max(res, indegree[i] + indegree[j] - graph[i][j]);
		}
		return res;
	}
};