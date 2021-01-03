#include <map>
#include <vector>
using namespace std;

class Solution
{
public:
	int countPairs(vector<int> &deliciousness)
	{
		int N = deliciousness.size();
		long res = 0;
		map<int, int> m;
		for (auto n : deliciousness)
			++m[n];
		for (int pow2 = 1; pow2 <= (1 << 21); pow2 <<= 1)
		{
			for (auto &[val, count] : m)
			{
				int n = pow2 - val;
				if (n < val)
					continue;
				if (m.find(n) != m.end())
				{
					if (n != val)
						res += (long)m[val] * m[n] % MOD;
					else
						res += (long)count * (count - 1) / 2 % MOD;
					res %= MOD;
				}
			}
		}
		return res;
	}

private:
	static const int MOD = 1e9 + 7;
};