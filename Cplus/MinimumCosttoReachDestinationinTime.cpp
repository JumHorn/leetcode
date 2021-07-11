#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

struct info
{
	int cost;
	int time;
	int city;
	info(int x, int y, int z) : cost(x), time(y), city(z)
	{
	}
};

bool operator<(const info &lhs, const info &rhs)
{
	return lhs.cost > rhs.cost;
}

class Solution
{
public:
	int minCost(int maxTime, vector<vector<int>> &edges, vector<int> &passingFees)
	{
		priority_queue<info> q; //{cost,time,city}
		int N = passingFees.size();
		vector<vector<pair<int, int>>> graph(N + 1); //{connected city,time}
		for (auto &e : edges)
		{
			graph[e[0]].push_back({e[1], e[2]});
			graph[e[1]].push_back({e[0], e[2]});
		}
		q.push(info(passingFees[0], 0, 0));
		vector<vector<int>> seen(N + 1, vector<int>(maxTime + 1, INT_MAX));
		seen[0][0] = passingFees[0];
		while (!q.empty())
		{
			int cost = q.top().cost, time = q.top().time, city = q.top().city;
			q.pop();
			for (auto [to, t] : graph[city])
			{
				if (time + t > maxTime)
					continue;
				if (seen[to][time + t] < cost + passingFees[to])
					continue;
				if (to == N - 1)
					return cost + passingFees[to];
				if (cost + passingFees[to] < seen[to][time + t])
				{
					seen[to][time + t] = cost + passingFees[to];
					q.push(info(cost + passingFees[to], time + t, to));
				}
			}
		}
		return -1;
	}
};