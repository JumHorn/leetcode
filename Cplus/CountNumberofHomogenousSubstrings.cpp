#include <string>
using namespace std;

class Solution
{
public:
	int countHomogenous(string s)
	{
		long N = s.length(), res = 0;
		for (int i = 0, j = 0; i <= N; ++i)
		{
			if (i == N || s[i] != s[j])
			{
				long n = i - j;
				res += n * (n + 1) / 2;
				res %= MOD;
				j = i;
			}
		}
		return res;
	}

private:
	static const int MOD = 1e9 + 7;
};