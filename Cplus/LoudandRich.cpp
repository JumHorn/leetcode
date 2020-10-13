#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> loudAndRich(vector<vector<int>> &richer, vector<int> &quiet)
	{
		int N = quiet.size();
		vector<vector<int>> graph(N);
		for (auto &rich : richer)
			graph[rich[1]].push_back(rich[0]);
		vector<int> res(N, N);
		for (int i = 0; i < N; ++i)
			dfs(graph, quiet, res, i);
		return res;
	}

	int dfs(vector<vector<int>> &graph, vector<int> &quiet, vector<int> &res, int index)
	{
		int N = graph.size();
		if (res[index] < N)
			return res[index];
		res[index] = index;
		for (auto n : graph[index])
		{
			int person = dfs(graph, quiet, res, n);
			if (quiet[person] < quiet[res[index]])
				res[index] = person;
		}
		return res[index];
	}
};