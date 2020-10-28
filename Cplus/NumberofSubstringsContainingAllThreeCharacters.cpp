#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
	int numberOfSubstrings(string s)
	{
		int res = 0, i = 0, N = s.length();
		unordered_map<char, int> m; //{char,count}
		for (int i = 0, j = 0; i < (int)s.length(); ++i)
		{
			++m[s[i]];
			while ((int)m.size() >= 3)
			{
				if (--m[s[j]] == 0)
					m.erase(s[j]);
				++j;
			}
			res += j;
		}
		return res;
	}
};