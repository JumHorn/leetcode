#include <string>
using namespace std;

class Solution
{
public:
	int countSubstrings(string s, string t)
	{
		int N1 = s.length(), N2 = t.length(), res = 0;
		for (int i = 0; i < N1; ++i)
		{
			for (int j = 0; j < N2; ++j)
			{
				int diff = 0;
				for (int k = 0; i + k < N1 && j + k < N2 && diff < 2; ++k)
				{
					if (s[i + k] != t[j + k])
						++diff;
					if (diff == 1)
						++res;
				}
			}
		}
		return res;
	}
};