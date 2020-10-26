#include <vector>
using namespace std;

class Solution
{
public:
	int findMaxConsecutiveOnes(vector<int> &nums)
	{
		int i = 0, j = 0, count = 0;
		for (; i < (int)nums.size(); ++i)
		{
			count += nums[i];
			if (i - j + 1 != count)
				count -= nums[j++];
		}
		return i - j;
	}
};