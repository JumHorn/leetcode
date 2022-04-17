#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int longestPath(vector<int> &parent, string s)
	{
		int N = parent.size();
		vector<vector<int>> graph(N);
		for (int i = 1; i < N; ++i)
			graph[parent[i]].push_back(i);
		int res = 1;
		postorder(graph, s, 0, -1, res);
		return res;
	}

	int postorder(vector<vector<int>> &graph, string &s, int at, int from, int &res)
	{
		int depth1 = 0, depth2 = 0;
		for (auto to : graph[at])
		{
			if (to == from)
				continue;
			int d = postorder(graph, s, to, at, res);
			if (s[at] != s[to])
			{
				if (d > depth1)
				{
					depth2 = depth1;
					depth1 = d;
				}
				else if (d > depth2)
					depth2 = d;
			}
			res = max(res, depth1 + depth2 + 1);
		}
		return depth1 + 1;
	}
};