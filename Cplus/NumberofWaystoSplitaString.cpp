#include <string>
using namespace std;

class Solution
{
public:
	int numWays(string s)
	{
		int n = s.length(), ones = 0;
		for (auto c : s)
		{
			if (c == '1')
				++ones;
		}
		if (ones % 3 != 0)
			return 0;
		if (ones == 0)
		{
			return long(n - 1) * long(n - 2) / 2 % MOD;
		}
		int m = ones / 3, a, b, i = 0;
		for (; i < n && m > 0; ++i)
		{
			if (s[i] == '1')
				--m;
		}
		int j = i;
		while (j < n && s[j] == '0')
			++j;
		a = j - i;
		m = ones / 3;
		for (i = j; i < n && m > 0; ++i)
		{
			if (s[i] == '1')
				--m;
		}
		j = i;
		while (j < n && s[j] == '0')
			++j;
		b = j - i;
		return long(a + 1) * long(b + 1) % MOD;
	}

private:
	static const int MOD = 1e9 + 7;
};
