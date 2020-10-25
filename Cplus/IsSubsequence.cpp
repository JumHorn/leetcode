#include <string>
using namespace std;

class Solution
{
public:
	bool isSubsequence(string s, string t)
	{
		int i = 0, j = 0, M = s.length(), N = t.length();
		for (; i < M && j < N; ++j)
		{
			if (s[i] == t[j])
				++i;
		}
		return i == M;
	}
};