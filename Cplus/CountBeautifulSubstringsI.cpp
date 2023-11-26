#include <string>
using namespace std;

class Solution
{
public:
	int beautifulSubstrings(string s, int k)
	{
		int N = s.size(), res = 0;
		for (int i = 0; i < N; ++i)
		{
			int v = 0, c = 0;
			for (int j = i; j >= 0; --j)
			{
				if (isVowels(s[j]))
					++v;
				else
					++c;
				if (c == v && c * v % k == 0)
					++res;
			}
		}
		return res;
	}

	bool isVowels(char c)
	{
		string vowels = "aeiou";
		for (auto n : vowels)
		{
			if (c == n)
				return true;
		}
		return false;
	}
};