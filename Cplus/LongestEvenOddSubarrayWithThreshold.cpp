#include <vector>
using namespace std;

class Solution
{
public:
	int longestAlternatingSubarray(vector<int> &nums, int threshold)
	{
		int N = nums.size(), res = 0;
		for (int i = 0; i < N; ++i)
		{
			if (nums[i] % 2 == 0 && nums[i] <= threshold)
			{
				int j = i + 1;
				for (; j < N && nums[j] <= threshold; ++j)
				{
					if (nums[j] % 2 == nums[j - 1] % 2)
						break;
				}
				res = max(res, j - i);
				i = j - 1;
			}
		}
		return res;
	}
};