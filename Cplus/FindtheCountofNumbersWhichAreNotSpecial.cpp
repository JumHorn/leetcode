#include <vector>
using namespace std;

class Solution
{
public:
	int nonSpecialCount(int l, int r)
	{
		vector<bool> prime(1e5 + 1);
		int res = 0, n = 1e5;
		for (int i = 2; i < n && i * i <= r; ++i)
		{
			if (!prime[i])
			{
				if (i * i >= l)
					++res;
				for (int j = i + i; j <= n; j += i)
					prime[j] = true;
			}
		}

		return r - l + 1 - res;
	}
};