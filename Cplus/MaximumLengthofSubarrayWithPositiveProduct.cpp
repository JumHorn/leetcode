#include <vector>
using namespace std;

class Solution
{
public:
	int getMaxLen(vector<int>& nums)
	{
		int res = 0, firstNegative = 0, countNegative = 0, base = -1;
		for (int i = 0; i < (int)nums.size(); ++i)
		{
			if (nums[i] == 0)
			{
				firstNegative = countNegative = 0;
				base = i;
			}
			else
			{
				if (nums[i] < 0)
				{
					if (countNegative == 0)
						firstNegative = i;
					++countNegative;
				}

				if (countNegative % 2 == 0)
					res = max(res, i - base);
				else
					res = max(res, i - firstNegative);
			}
		}
		return res;
	}
};
