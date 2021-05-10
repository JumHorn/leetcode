#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
	int numberOfSubstrings(string s)
	{
		int res = 0, N = s.length();
		unordered_map<char, int> m; //{char,count}
		for (int i = 0, j = 0; i < N; ++i)
		{
			++m[s[i]];
			for (; (int)m.size() >= 3; ++j)
			{
				if (--m[s[j]] == 0)
					m.erase(s[j]);
			}
			res += j;
		}
		return res;
	}
};