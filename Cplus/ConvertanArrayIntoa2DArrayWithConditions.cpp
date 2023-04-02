#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> findMatrix(vector<int> &nums)
	{
		unordered_map<int, int> m; //{val,count}
		int maxcount = 0;
		for (auto n : nums)
			maxcount = max(maxcount, ++m[n]);
		vector<vector<int>> res(maxcount);
		for (auto &v : res)
		{
			for (auto &p : m)
			{
				if (p.second > 0)
				{
					--p.second;
					v.push_back(p.first);
				}
			}
		}
		return res;
	}
};