#include <string>
#include <climits>
#include <unordered_map>
using namespace std;

class Solution
{
public:
	string minWindow(string s, string t)
	{
		unordered_map<char, int> charmap;
		int i = 0, j = -1, window = INT_MAX, start = 0, n = t.length();
		for (int k = 0; k < n; k++)
			++charmap[t[k]];
		while (++j < (int)s.length())
		{
			if (--charmap[s[j]] >= 0)
				--n;
			if (window <= j - i + 1 && ++charmap[s[i++]] > 0)
				++n;
			if (n == 0)
			{
				while (i <= j && ++charmap[s[i]] <= 0)
					++i;
				++n;
				window = j - i + 1;
				start = i++;
			}
		}
		if (window == INT_MAX)
			return "";
		return s.substr(start, window);
	}
};