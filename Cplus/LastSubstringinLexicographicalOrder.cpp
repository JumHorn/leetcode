#include <algorithm>
#include <string>
using namespace std;

class Solution
{
public:
	string lastSubstring(string s)
	{
		int N = s.length();
		auto iter = max_element(s.begin(), s.end());
		int res = distance(s.begin(), iter);
		for (int i = res + 1; i < N; ++i)
		{
			if (s[i] == *iter)
			{
				int j = res, k = i;
				while (i < N && s[++i] == s[++j])
					;
				if (i == N)
					break;
				if (s[i] > s[j])
				{
					res = k;
					i = k;
				}
				else
					--i;
			}
		}
		return s.substr(res);
	}
};