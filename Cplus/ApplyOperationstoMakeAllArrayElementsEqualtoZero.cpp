#include <vector>
using namespace std;

class Solution
{
public:
	bool checkArray(vector<int> &nums, int k)
	{
		int N = nums.size();
		for (int i = 1; i < k; ++i)
		{
			if (nums[i] < nums[i - 1])
				return false;
		}
		long long diff = 0;
		for (int i = k, j = 0; i < N; ++i, ++j)
		{
			diff += (j > 0 ? (nums[j] - nums[j - 1]) : nums[j]);
			if (nums[i] + diff < nums[i - 1])
				return false;
			nums[i] += diff;
		}
		for (int diff = nums[N - k], i = N - k + 1; i < N; ++i)
		{
			if (nums[i] != diff)
				return false;
		}
		return true;
	}
};