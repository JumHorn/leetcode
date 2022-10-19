#include <vector>
using namespace std;

class Solution
{
public:
	int superPow(int a, vector<int> &b)
	{
		a %= 1337;
		if (a == 0)
			return 0;
		int res = 1;
		for (auto n : b)
			res = modPow(res, 10) * modPow(a, n) % MOD;
		return res;
	}

	int modPow(int x, int n) //pow(x,n) with MOD
	{
		long long res = 1;
		for (auto i = n; i > 0; i /= 2)
		{
			if (i % 2)
				res = res * x % MOD;
			x = x * x % MOD;
		}
		return res;
	}

private:
	static const int MOD = 1337;
};