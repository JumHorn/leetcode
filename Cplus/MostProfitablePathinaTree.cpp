#include <climits>
#include <vector>
using namespace std;

class Solution
{
public:
	int mostProfitablePath(vector<vector<int>> &edges, int bob, vector<int> &amount)
	{
		int N = amount.size();
		vector<vector<int>> graph(N);
		for (auto &edge : edges)
		{
			graph[edge[0]].push_back(edge[1]);
			graph[edge[1]].push_back(edge[0]);
		}
		vector<int> bobtime(N, INT_MAX);
		postorder(graph, 0, 0, bob, bobtime);
		int res = INT_MIN, income = 0;
		preorder(graph, 0, 0, amount, bobtime, 1, income, res);
		return res;
	}

	void preorder(vector<vector<int>> &graph, int from, int at, vector<int> &amount, vector<int> &bobtime, int time, int income, int &res)
	{
		if (time == bobtime[at])
			income += amount[at] / 2;
		else if (time < bobtime[at])
			income += amount[at];

		if (at != 0 && graph[at].size() == 1) //leaf node
			res = max(res, income);

		for (auto &to : graph[at])
		{
			if (to != from)
				preorder(graph, at, to, amount, bobtime, time + 1, income, res);
		}
	}

	int postorder(vector<vector<int>> &graph, int from, int at, int bob, vector<int> &bobtime)
	{
		if (at == bob)
			return bobtime[at] = 1;
		for (auto &to : graph[at])
		{
			if (to != from)
			{
				int b = postorder(graph, at, to, bob, bobtime);
				if (b != 0)
					return bobtime[at] = b + 1;
			}
		}
		return 0;
	}
};