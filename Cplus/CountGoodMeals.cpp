#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int countPairs(vector<int> &deliciousness)
	{
		long res = 0;
		unordered_map<int, int> m;
		for (auto n : deliciousness)
		{
			for (int pow2 = 1; pow2 <= (1 << 21); pow2 <<= 1)
			{
				int val = pow2 - n;
				auto iter = m.find(val);
				if (iter != m.end())
					res = (res + iter->second) % MOD;
			}
			++m[n];
		}
		return res;
	}

private:
	static const int MOD = 1e9 + 7;
};