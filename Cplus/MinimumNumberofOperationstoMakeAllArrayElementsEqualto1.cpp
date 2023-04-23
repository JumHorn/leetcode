#include <vector>
using namespace std;

class Solution
{
public:
	int minOperations(vector<int> &nums)
	{
		int g = gcd(nums), N = nums.size();
		if (g > 1)
			return -1;
		int ones = 0;
		for (auto n : nums)
		{
			if (n == 1)
				++ones;
		}
		if (ones > 0)
			return N - ones;
		for (int l = 2; l <= 50; ++l)
		{
			for (int i = 0; i <= N - l; ++i)
			{
				if (gcd(nums, i, i + l) == 1)
					return N - ones + l - 2;
			}
		}
		return -1;
	}

	int gcd(int x, int y)
	{
		return x == 0 ? y : gcd(y % x, x);
	}

	int gcd(vector<int> &nums, int start, int end)
	{
		int g = nums[start];
		for (int i = start; i < end; ++i)
		{
			int n = nums[i];
			g = gcd(n, g);
			if (g == 1)
				return g;
		}
		return g;
	}

	int gcd(vector<int> &nums)
	{
		return gcd(nums, 0, nums.size());
	}
};