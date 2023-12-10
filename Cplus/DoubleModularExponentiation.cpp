#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> getGoodIndices(vector<vector<int>> &variables, int target)
	{
		vector<int> res;
		int index = -1;
		for (auto v : variables)
		{
			++index;
			int a = v[0], b = v[1], c = v[2], m = v[3];
			long long t = modPow(a, b, 10);
			if (modPow(t, c, m) == target)
				res.push_back(index);
		}
		return res;
	}

	long long modPow(long long x, int n, int MOD)
	{
		long long res = 1;
		for (int i = n; i > 0; i /= 2)
		{
			if (i % 2)
				res = res * x % MOD;
			x = x * x % MOD;
		}
		return res;
	}
};