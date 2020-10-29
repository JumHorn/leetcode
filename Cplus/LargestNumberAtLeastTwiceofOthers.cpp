#include <vector>
using namespace std;

class Solution
{
public:
	int dominantIndex(vector<int> &nums)
	{
		int N = nums.size();
		if (N <= 1)
			return 0;
		int first = 0, second = 1;
		for (int i = 1; i < N; ++i)
		{
			if (nums[i] > nums[first])
			{
				second = first;
				first = i;
			}
			else if (nums[i] > nums[second])
				second = i;
		}
		return nums[first] >= 2 * nums[second] ? first : -1;
	}
};