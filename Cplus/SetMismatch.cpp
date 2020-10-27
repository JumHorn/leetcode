#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> findErrorNums(vector<int> &nums)
	{
		int N = nums.size();
		for (int i = 0; i < N;)
		{
			if (i + 1 == nums[i] || nums[nums[i] - 1] == nums[i])
				++i;
			else
				swap(nums[nums[i] - 1], nums[i]);
		}
		for (int i = 0; i < N; ++i)
		{
			if (nums[i] != i + 1)
				return {nums[i], i + 1};
		}
		return {};
	}
};