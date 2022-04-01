#include <vector>
using namespace std;

class Solution
{
public:
	int minTime(int n, vector<vector<int>> &edges, vector<bool> &hasApple)
	{
		vector<vector<int>> graph(n);
		for (auto &edge : edges)
		{
			graph[edge[0]].push_back(edge[1]);
			graph[edge[1]].push_back(edge[0]);
		}
		int res = postorder(graph, 0, -1, hasApple);
		return res >= 0 ? res : 0;
	}

	// no apple return -1,hash apple return time needed
	int postorder(vector<vector<int>> &graph, int at, int from, vector<bool> &hasApple)
	{
		int res = 0;
		for (auto &to : graph[at])
		{
			if (to == from)
				continue;
			int time = postorder(graph, to, at, hasApple);
			if (time >= 0)
				res += time + 2;
		}
		return (!hasApple[at] && res == 0) ? -1 : res;
	}
};