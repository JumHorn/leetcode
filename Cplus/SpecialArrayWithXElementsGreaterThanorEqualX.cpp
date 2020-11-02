#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int specialArray(vector<int> &nums)
	{
		sort(nums.begin(), nums.end());
		int X = 1, N = nums.size();
		for (int i = N - 1; i >= 0; --i, ++X)
		{
			if (X > nums[i])
				return -1;
			if (i == 0 || X > nums[i - 1])
				return X;
		}
		return -1;
	}
};