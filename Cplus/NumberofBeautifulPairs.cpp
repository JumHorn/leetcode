#include <vector>
using namespace std;

class Solution
{
public:
	int countBeautifulPairs(vector<int> &nums)
	{
		int N = nums.size(), res = 0;
		for (int i = 0; i < N; ++i)
		{
			for (int j = i + 1; j < N; ++j)
			{
				int a = nums[i], b = nums[j] % 10;
				while (a / 10 != 0)
					a /= 10;
				if (gcd(a, b) == 1)
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