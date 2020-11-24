#include <vector>
using namespace std;

class Solution
{
public:
	bool isGoodArray(vector<int> &nums)
	{
		int g = nums[0];
		for (auto n : nums)
		{
			g = gcd(n, g);
			if (g == 1)
				return true;
		}
		return false;
	}

	int gcd(int x, int y)
	{
		return x == 0 ? y : gcd(y % x, x);
	}
};