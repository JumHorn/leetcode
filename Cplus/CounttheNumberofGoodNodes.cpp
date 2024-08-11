#include <vector>
using namespace std;

class Solution
{
public:
	int countGoodNodes(vector<vector<int>> &edges)
	{
		int n = edges.size() + 1;
		vector<vector<int>> graph(n);
		for (auto &v : edges)
		{
			graph[v[0]].push_back(v[1]);
			graph[v[1]].push_back(v[0]);
		}
		int res = 0;
		postorder(graph, -1, 0, res);
		return res;
	}

	int postorder(vector<vector<int>> &graph, int from, int at, int &res)
	{
		int count = 0, pre = 0, flag = 0;
		for (auto to : graph[at])
		{
			if (to != from)
			{
				int count1 = postorder(graph, at, to, res);
				count += count1;
				if (pre != 0 && pre != count1)
					flag = 1;
				pre = count1;
			}
		}
		if (flag == 0)
			++res;
		return count + 1;
	}
};