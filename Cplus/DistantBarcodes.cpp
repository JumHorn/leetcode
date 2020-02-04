#include <algorithm>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> rearrangeBarcodes(vector<int>& barcodes)
	{
		unordered_map<int, int> m;
		priority_queue<pair<int, int>> q;
		for (int i = 0; i < (int)barcodes.size(); i++)
			++m[barcodes[i]];
		for (auto n : m)
			q.push({n.second, n.first});
		vector<int> res;
		auto tmp = q.top();
		q.pop();
		res.push_back(tmp.second);
		if (--tmp.first > 0)
			q.push(tmp);
		while (!q.empty())
		{
			auto top1 = q.top();
			q.pop();
			if (top1.second != res.back())
			{
				res.push_back(top1.second);
				if (--top1.first > 0)
					q.push(top1);
				continue;
			}
			auto top2 = q.top();
			q.pop();
			res.push_back(top2.second);
			if (--top2.first > 0)
				q.push(top2);
			q.push(top1);
		}
		return res;
	}
};
