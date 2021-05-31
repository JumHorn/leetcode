#include <string>
using namespace std;

class Solution
{
public:
	int countGoodSubstrings(string s)
	{
		int N = s.length(), res = 0;
		for (int i = 0; i <= N - 3; ++i)
		{
			if (s[i] != s[i + 1] && s[i] != s[i + 2] && s[i + 1] != s[i + 2])
				++res;
		}
		return res;
	}
};