#include <vector>
using namespace std;

class Solution
{
public:
	int firstMissingPositive(vector<int> &nums)
	{
		int n = nums.size();
		for (int i = 0; i < n; i++)
		{
			if (nums[i] == i + 1 || nums[i] < 1 || nums[i] > n)
				continue;
			if (nums[i] != nums[nums[i] - 1])
			{
				swap(nums[i], nums[nums[i] - 1]);
				i--;
			}
		}
		for (int i = 0; i < n; i++)
			if (nums[i] != i + 1)
				return i + 1;
		return n + 1;
	}
};
