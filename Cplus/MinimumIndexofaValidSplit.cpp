#include <vector>
using namespace std;

class Solution
{
public:
	int minimumIndex(vector<int> &nums)
	{
		int M = majorityElement(nums), count = 0, N = nums.size();
		for (auto n : nums)
		{
			if (n == M)
				++count;
		}
		int count1 = 0;
		for (int i = 0; i < N; ++i)
		{
			if (nums[i] == M)
				++count1;
			if (count1 * 2 > (i + 1) && (count - count1) * 2 > (N - i - 1))
				return i;
		}
		return -1;
	}

	int majorityElement(vector<int> &nums)
	{
		int val = 0, count = 0;
		for (auto n : nums)
		{
			if (val == n)
				++count;
			else if (count == 0)
			{
				val = n;
				count = 1;
			}
			else
				--count;
		}
		return val;
	}
};