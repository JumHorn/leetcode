#include <string>
using namespace std;

class Solution
{
public:
	int minimumLength(string s)
	{
		int i = 0, j = s.length() - 1;
		while (i < j && s[i] == s[j])
		{
			int l = i + 1, r = j - 1;
			while (l < r && s[l] == s[i])
				++l;
			while (l < r && s[r] == s[j])
				--r;
			if (l >= r && s[i] == s[l])
				return 0;
			i = l;
			j = r;
		}
		return max(0, j - i + 1);
	}
};