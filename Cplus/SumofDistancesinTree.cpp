#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges)
	{
		vector<unordered_set<int>> graph(N);
		for (auto& edge : edges)
		{
			graph[edge[0]].insert(edge[1]);
			graph[edge[1]].insert(edge[0]);
		}
		vector<int> res(N), nodecount(N);
		dfs(graph, nodecount, 0);
		res[0] = node0distance(graph, nodecount, 0);
		preorder(graph, nodecount, res, 0);
		return res;
	}

	void preorder(vector<unordered_set<int>>& graph, vector<int>& nodecount, vector<int>& dis, int node)
	{
		int N = graph.size();
		for (auto n : graph[node])
		{
			dis[n] = dis[node] + N - 2 * nodecount[n];
			preorder(graph, nodecount, dis, n);
		}
	}

	int node0distance(vector<unordered_set<int>>& graph, vector<int>& nodecount, int node)
	{
		int res = 0;
		for (auto n : graph[node])
		{
			res += node0distance(graph, nodecount, n) + nodecount[n];
		}
		return res;
	}

	int dfs(vector<unordered_set<int>>& graph, vector<int>& nodecount, int node)
	{
		int res = 1;
		for (auto n : graph[node])
		{
			graph[n].erase(node);
			res += dfs(graph, nodecount, n);
		}
		nodecount[node] = res;
		return res;
	}
};
