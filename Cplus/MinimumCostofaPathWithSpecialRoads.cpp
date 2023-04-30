#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int minimumCost(vector<int> &start, vector<int> &target, vector<vector<int>> &specialRoads)
	{
		priority_queue<pair<long, long>, vector<pair<long, long>>, greater<pair<long, long>>> q; //{cost,pos(M*N)}
		long N = 1e5 + 1, res = abs(start[0] - target[0]) + abs(start[1] - target[1]);
		unordered_map<long, long> seen;
		seen[start[0] * N + start[1]] = 0;
		q.push({0L, start[0] * N + start[1]});
		while (!q.empty())
		{
			long cost = q.top().first, x = q.top().second / N, y = q.top().second % N;
			q.pop();
			if (cost > seen[x * N + y] || cost > res) // avoid outdated
				continue;
			res = min(res, cost + abs(x - target[0]) + abs(y - target[1]));
			for (auto &r : specialRoads)
			{
				long ncost = cost + abs(x - r[0]) + abs(y - r[1]) + r[4];
				if (seen.find(r[2] * N + r[3]) == seen.end() || ncost < seen[r[2] * N + r[3]])
				{
					seen[r[2] * N + r[3]] = ncost;
					q.push({ncost, r[2] * N + r[3]});
				}
			}
		}
		return res;
	}
};