#include <vector>
using namespace std;

class Solution
{
public:
	int superPow(int a, vector<int>& b)
	{
		a %= 1337;
		if (a == 0)
			return 0;
		return superPow(a, b, b.size() - 1);
	}

	int superPow(int a, vector<int>& b, int index)
	{
		if (index == 0)
			return powMod(a, b[0], MOD);
		return powMod(superPow(a, b, index - 1), 10, MOD) * powMod(a, b[index], MOD) % MOD;
	}

	int powMod(int a, int b, int mod)
	{
		int res = 1;
		for (int i = 0; i < b; i++)
			res = (res * a) % mod;
		return res;
	}

private:
	static const int MOD = 1337;
};
