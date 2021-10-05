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
		return recursive(a, b, b.size() - 1);
	}

	int recursive(int a, vector<int> &b, int index)
	{
		if (index < 0)
			return 1;
		return modPow(recursive(a, b, index - 1), 10) * modPow(a, b[index]) % MOD;
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