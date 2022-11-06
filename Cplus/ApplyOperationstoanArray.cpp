#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> applyOperations(vector<int> &nums)
	{
		int N = nums.size();
		for (int i = 1; i < N; ++i)
		{
			if (nums[i] == nums[i - 1])
			{
				nums[i - 1] <<= 1;
				nums[i] = 0;
			}
		}
		shiftZero(nums);
		return nums;
	}

	void shiftZero(vector<int> &nums)
	{
		int N = nums.size(), j = 0;
		for (int i = 0; i < N; ++i)
		{
			if (nums[i] != 0)
				nums[j++] = nums[i];
		}
		for (; j < N; ++j)
			nums[j] = 0;
	}
};