#include <string>
using namespace std;
/*
match pattern using recusion
match from right to left

follow up:
can use memdp to optimize time complexity
*/
class Solution
{
public:
	bool isMatch(string s, string p)
	{
		return doIsMatch(s, s.length() - 1, p, p.length() - 1);
	}

	bool doIsMatch(const string &s, int i, const string &p, int j)
	{
		if (i < 0 && j < 0)
			return true;
		if (j < 0)
			return false;
		if (i < 0)
		{
			while (j >= 0 && p[j] == '*')
				j -= 2;
			return j < 0;
		}
		if (p[j] == '.' || p[j] == s[i])
			return doIsMatch(s, i - 1, p, j - 1);
		if (p[j] == '*')
		{
			if (p[j - 1] == '.' || p[j - 1] == s[i])
				return doIsMatch(s, i - 1, p, j) || doIsMatch(s, i, p, j - 2) || doIsMatch(s, i - 1, p, j - 2);
			else
				return doIsMatch(s, i, p, j - 2);
		}
		return false;
	}
};