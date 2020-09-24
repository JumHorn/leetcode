#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> topKFrequent(vector<int> &nums, int k)
	{
		vector<int> res;
		unordered_map<int, int> m;
		for (auto n : nums)
			++m[n];
		priority_queue<pair<int, int>> q;
		for (auto iter : m)
		{
			if (q.size() < k)
				q.push({-iter.second, iter.first});
			else if (iter.second > -q.top().first)
			{
				q.pop();
				q.push({-iter.second, iter.first});
			}
		}
		while (!q.empty())
		{
			res.push_back(q.top().second);
			q.pop();
		}
		return res;
	}
};