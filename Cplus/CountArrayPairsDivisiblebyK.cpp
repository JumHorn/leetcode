#include <vector>
using namespace std;

class Solution
{
public:
	long long coutPairs(vector<int> &nums, int k)
	{
		vector<int> count(1e5 + 1);
		long long res = 0;
		for (auto n : nums)
		{
			int g = gcd(n, k);
			int p = k / g;
			res += count[p];
			int i = 1;
			for (; i * i < n; ++i)
			{
				if (n % i == 0)
				{
					++count[i];
					++count[n / i];
				}
			}
			if (i * i == n)
				++count[i];
		}
		return res;
	}

	int gcd(int x, int y)
	{
		return x == 0 ? y : gcd(y % x, x);
	}
};