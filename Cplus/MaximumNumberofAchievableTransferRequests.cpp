#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
	int maximumRequests(int n, vector<vector<int>> &requests)
	{
		vector<vector<int>> graph(n, vector<int>(n));
		int res = 0;
		for (auto &request : requests)
		{
			if (request[0] != request[1])
				++graph[request[0]][request[1]];
			else
				++res;
		}
		for (int i = 0; i < n; ++i)
		{
			vector<int> seen(n);
			stack<int> order;
			if (dfs(graph, i, seen, order))
			{
				--i;
				++res;
				int end = order.top();
				order.pop();
				--graph[order.top()][end];
				while (end != order.top())
				{
					int to = order.top();
					order.pop();
					int at = order.top();
					--graph[at][to];
					++res;
				}
			}
		}
		return res;
	}

	bool dfs(vector<vector<int>> &graph, int at, vector<int> &seen, stack<int> &order)
	{
		int N = graph.size();
		order.push(at);
		if (seen[at] == 1)
			return true;
		seen[at] = 1;
		for (int i = 0; i < N; ++i)
		{
			if (graph[at][i] > 0)
			{
				if (dfs(graph, i, seen, order))
					return true;
			}
		}
		seen[at] = 0;
		order.pop();
		return false;
	}
};