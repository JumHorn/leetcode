#include <vector>
using namespace std;

class Solution
{
public:
	int countPrimes(int n)
	{
		vector<bool> prime(n + 1);
		int res = 0;
		for (int i = 2; i < n; ++i)
		{
			if (!prime[i])
			{
				++res;
				for (int j = 1; j * i <= n; ++j)
					prime[j * i] = true;
			}
		}
		return res;
	}
};