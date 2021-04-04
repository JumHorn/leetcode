#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

class Solution
{
public:
	int countDifferentSubsequenceGCDs(vector<int> &nums)
	{
		int maxval = *max_element(nums.begin(), nums.end());
		vector<bool> seen(maxval + 1);
		for (auto n : nums)
			seen[n] = true;
		int res = 0;
		for (int i = 1; i <= maxval; ++i)
		{
			int g = 0;
			for (int j = i; j <= maxval; j += i)
			{
				if (seen[j])
					g = gcd(g, j);
			}
			if (g == i)
				++res;
		}
		return res;
	}

	int gcd(int x, int y)
	{
		return x == 0 ? y : gcd(y % x, x);
	}
};