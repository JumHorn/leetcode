#include <vector>
using namespace std;

class Solution
{
public:
	int subarrayGCD(vector<int> &nums, int k)
	{
		int N = nums.size(), res = 0;
		for (int i = 0; i < N; ++i)
		{
			int g = nums[i];
			for (int j = i; j < N && g % k == 0; ++j)
			{
				g = gcd(g, nums[j]);
				if (g == k)
					++res;
			}
		}
		return res;
	}

	int gcd(int x, int y)
	{
		return x == 0 ? y : gcd(y % x, x);
	}
};