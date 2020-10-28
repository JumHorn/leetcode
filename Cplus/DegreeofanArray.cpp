#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int findShortestSubArray(vector<int> &nums)
	{
		unordered_map<int, vector<int>> m; //{value,{count,left index,right index}}
		for (int i = 0; i < (int)nums.size(); ++i)
		{
			if (m.find(nums[i]) == m.end())
				m.insert({nums[i], {1, i, i}});
			else
			{
				++m[nums[i]][0];
				m[nums[i]][2] = i;
			}
		}
		int res = nums.size(), degree = 0;
		for (auto &n : m)
		{
			if (n.second[0] > degree)
			{
				degree = n.second[0];
				res = n.second[2] - n.second[1] + 1;
			}
			else if (n.second[0] == degree)
				res = min(res, n.second[2] - n.second[1] + 1);
		}
		return res;
	}
};