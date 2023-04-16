#include <vector>
using namespace std;

class Solution
{
public:
	int minimumTotalPrice(int n, vector<vector<int>> &edges, vector<int> &price, vector<vector<int>> &trips)
	{
		vector<vector<int>> graph(n);
		for (auto &edge : edges)
		{
			graph[edge[0]].push_back(edge[1]);
			graph[edge[1]].push_back(edge[0]);
		}
		// calc node counts in all trips
		vector<int> count(n);
		for (auto &t : trips)
			preorder(graph, -1, t[0], t[1], count);
		auto [halve, nothalve] = postorder(graph, -1, 0, count, price);
		return min(halve, nothalve);
	}

	bool preorder(vector<vector<int>> &graph, int from, int at, int end, vector<int> &count)
	{
		if (at == end)
		{
			++count[at];
			return true;
		}
		for (auto to : graph[at])
		{
			if (to != from && preorder(graph, at, to, end, count))
			{
				++count[at];
				return true;
			}
		}
		return false;
	}

	pair<int, int> postorder(vector<vector<int>> &graph, int from, int at, vector<int> &count, vector<int> &price)
	{
		int nothalve = price[at] * count[at], halve = nothalve / 2;
		for (auto to : graph[at])
		{
			if (to == from)
				continue;
			auto [h, nh] = postorder(graph, at, to, count, price);
			halve += nh;
			nothalve += min(h, nh);
		}
		return {halve, nothalve};
	}
};
