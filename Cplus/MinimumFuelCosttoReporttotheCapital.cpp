#include <vector>
using namespace std;

class Solution
{
public:
	long long minimumFuelCost(vector<vector<int>> &roads, int seats)
	{
		int N = roads.size() + 1;
		vector<vector<int>> graph(N);
		for (auto &r : roads)
		{
			graph[r[0]].push_back(r[1]);
			graph[r[1]].push_back(r[0]);
		}
		return postorder(graph, -1, 0, seats).first;
	}

	pair<long long, int> postorder(vector<vector<int>> &graph, int from, int at, int seats)
	{
		long long fuel = 0;
		int rep = 1;
		for (auto to : graph[at])
		{
			if (to != from)
			{
				auto res = postorder(graph, at, to, seats);
				fuel += res.first;
				fuel += (res.second + seats - 1) / seats;
				rep += res.second;
			}
		}
		return {fuel, rep};
	}
};