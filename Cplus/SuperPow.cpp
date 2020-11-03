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
		return powMod(recursive(a, b, index - 1), 10) * powMod(a, b[index]) % MOD;
	}

	int powMod(int a, int b) //pow(a,b) with MOD
	{
		int res = 1;
		for (int i = 0; i < b; ++i)
			res = (res * a) % MOD;
		return res;
	}

private:
	static const int MOD = 1337;
};