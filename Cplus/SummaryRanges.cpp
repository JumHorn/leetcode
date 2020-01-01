#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<string> summaryRanges(vector<int>& nums)
	{
		int i = 0, j = 1;
		vector<string> res;
		while (j <= (int)nums.size())
		{
			if (j == (int)nums.size() || nums[j - 1] + 1 != nums[j])
			{
				if (j - 1 == i)
					res.push_back(to_string(nums[i]));
				else
					res.push_back(to_string(nums[i]) + "->" + to_string(nums[j - 1]));
				i = j++;
			}
			else
				j++;
		}
		return res;
	}
};
