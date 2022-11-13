#include <vector>
using namespace std;

class Solution
{
public:
	int subarrayLCM(vector<int> &nums, int k)
	{
		int N = nums.size(), res = 0;
		for (int i = 0; i < N; ++i)
		{
			int lcm = nums[i];
			for (int j = i; j < N && lcm <= k; ++j)
			{
				int g = gcd(lcm, nums[j]);
				lcm = lcm * nums[j] / g;
				if (lcm == k)
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