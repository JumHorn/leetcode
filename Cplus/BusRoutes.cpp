#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	int numBusesToDestination(vector<vector<int>> &routes, int S, int T)
	{
		if (S == T)
			return 0;
		unordered_map<int, vector<int>> station; //{BusStop,{all bus route}}
		int N = routes.size();
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < (int)routes[i].size(); ++j)
				station[routes[i][j]].push_back(i);
		}
		queue<int> q;
		unordered_set<int> seen;
		q.push(S);
		int res = 0;
		while (!q.empty())
		{
			++res;
			int size = q.size();
			while (--size >= 0)
			{
				int stop = q.front();
				q.pop();
				for (auto r : station[stop]) //route in the bus stop
				{
					if (seen.find(r) != seen.end())
						continue;
					seen.insert(r);
					for (auto n : routes[r]) //all the stops
					{
						q.push(n);
						if (n == T)
							return res;
					}
				}
			}
		}
		return -1;
	}
};