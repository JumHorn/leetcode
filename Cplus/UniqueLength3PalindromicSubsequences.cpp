#include <string>
using namespace std;

class Solution
{
public:
	int countPalindromicSubsequence(string s)
	{
		int N = s.length(), res = 0;
		for (char c = 'a'; c <= 'z'; ++c)
		{
			int i = 0, j = N - 1;
			while (i < j - 1 && s[i] != c)
				++i;
			while (i + 1 < j && s[j] != c)
				--j;
			if (j - i >= 1 && s[i] == c && s[j] == c)
			{
				int mask = 0;
				for (int k = i + 1; k < j; ++k)
					mask |= (1 << (s[k] - 'a'));
				res += bitCount(mask);
			}
		}
		return res;
	}

	int bitCount(int n)
	{
		int res = 0;
		for (; n != 0; n &= n - 1)
			++res;
		return res;
	}
};