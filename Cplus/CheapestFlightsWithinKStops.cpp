#include <algorithm>
#include <climits>
#include <functional>
#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
	int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int K)
	{
		vector<vector<pair<int, int>>> graph(n);
		for (auto &flight : flights)
			graph[flight[0]].push_back({flight[1], flight[2]});
		priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q; //{price,pos,stops}
		q.push({0, src, K + 1});
		while (!q.empty())
		{
			int price = q.top()[0], pos = q.top()[1], stops = q.top()[2];
			q.pop();
			if (pos == dst)
				return price;
			if (stops == 0)
				continue;
			for (int i = 0; i < (int)graph[pos].size(); ++i)
				q.push({price + graph[pos][i].second, graph[pos][i].first, stops - 1});
		}
		return -1;
	}
};