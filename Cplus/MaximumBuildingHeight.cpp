#include <algorithm>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxBuilding(int n, vector<vector<int>> &restrictions)
	{
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q; //{height,building id}
		for (auto &r : restrictions)
			q.push({r[1], r[0]});
		if (q.empty())
			return n - 1;
		int res = 1, height = q.top().first;
		unordered_map<int, int> buildings; //{building id,height}
		buildings[1] = 0;
		while (!q.empty())
		{
			auto top = q.top();
			q.pop();
			auto iter = buildings.find(top.second);
			if (iter != buildings.end())
				continue;
			int h = min(top.first, top.second - 1);
			buildings[top.second] = h;
			res = max(res, h);
			if (top.second - 1 > 1 && buildings.find(top.second - 1) == buildings.end())
				q.push({h + 1, top.second - 1});
			if (top.second + 1 <= n && buildings.find(top.second + 1) == buildings.end())
				q.push({h + 1, top.second + 1});
		}
		return res;
	}
};