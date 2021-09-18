#include <cmath>
#include <vector>
using namespace std;

class Solution
{
public:
	int countKDifference(vector<int> &nums, int k)
	{
		int N = nums.size(), res = 0;
		for (int i = 0; i < N; ++i)
		{
			for (int j = i + 1; j < N; ++j)
			{
				if (abs(nums[i] - nums[j]) == k)
					++res;
			}
		}
		return res;
	}
};