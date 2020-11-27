#include <string>
using namespace std;

class Solution
{
public:
	string longestPrefix(string s)
	{
		long p = 1, prefix = 0, suffix = 0, N = s.length(), res = 0;
		for (int i = 0, j = 0; i < N - 1; ++i)
		{
			prefix = (prefix + s[i] * p) % MOD;
			j = N - i - 1;
			suffix = (suffix * 31 + s[j]) % MOD;
			p = p * 31 % MOD;
			if (prefix == suffix)
				res = i + 1;
		}
		return s.substr(0, res);
	}

private:
	static const int MOD = 1e9 + 7;
};