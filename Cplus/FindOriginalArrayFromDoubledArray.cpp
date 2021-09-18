#include <map>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> findOriginalArray(vector<int> &changed)
	{
		int N = changed.size();
		if (N % 2 == 1)
			return {};
		map<int, int> m; //{val,count}
		for (auto n : changed)
			++m[n];
		vector<int> res;
		while (!m.empty())
		{
			auto iter = m.begin();
			int val = iter->first;
			if (--iter->second == 0)
				m.erase(iter);
			if (m.find(val * 2) == m.end())
				return {};
			res.push_back(val);
			if (--m[val * 2] == 0)
				m.erase(val * 2);
		}
		return res;
	}
};