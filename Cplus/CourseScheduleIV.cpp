#include <vector>
using namespace std;

/*
Floyd–Warshall Algorithm
*/

class Solution
{
public:
	vector<bool> checkIfPrerequisite(int n, vector<vector<int>> &prerequisites, vector<vector<int>> &queries)
	{
		vector<vector<bool>> graph(n, vector<bool>(n));
		for (auto &v : prerequisites)
			graph[v[0]][v[1]] = true;
		for (int k = 0; k < n; ++k)
		{
			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < n; ++j)
					graph[i][j] = graph[i][j] || (graph[i][k] && graph[k][j]);
			}
		}
		vector<bool> res;
		for (auto &q : queries)
			res.push_back(graph[q[0]][q[1]]);
		return res;
	}
};