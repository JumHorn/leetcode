#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<string> summaryRanges(vector<int> &nums)
	{
		if (nums.empty())
			return {};
		vector<string> res;
		res.push_back(to_string(nums[0]));
		for (int i = 1, j = 0; i < (int)nums.size(); ++i)
		{
			if ((long)nums[i] - nums[i - 1] == 1)
				res.back() = to_string(nums[j]) + "->" + to_string(nums[i]);
			else
			{
				res.push_back(to_string(nums[i]));
				j = i;
			}
		}
		return res;
	}
};