#include <string>
using namespace std;

class Solution
{
public:
	int numSub(string s)
	{
		int N = s.length();
		long res = 0;
		for (int i = 0, j = 0; i <= N; ++i)
		{
			if (i == N || s[i] == '0')
			{
				long n = i - j;
				res = (res + n * (n + 1) / 2) % MOD;
				j = i + 1;
			}
		}
		return res;
	}

private:
	static const int MOD = 1e9 + 7;
};