#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> maxGeneticDifference(vector<int> &parents, vector<vector<int>> &queries)
	{
		int N = parents.size(), root = -1;
		vector<vector<int>> graph(N + 1);
		for (int i = 0; i < N; ++i)
		{
			if (parents[i] != -1)
				graph[i].push_back(parents[i]);
		}
		vector<int> res;
		for (auto &q : queries)
		{
			int val = q[1] ^ q[0], node = q[0];
			while (!graph[node].empty())
			{
				node = graph[node][0];
				val = max(val, q[1] ^ node);
			}
			res.push_back(val);
		}
		return res;
	}
};