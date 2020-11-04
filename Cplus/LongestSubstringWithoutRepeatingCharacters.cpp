#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
	int lengthOfLongestSubstring(string s)
	{
		unordered_map<char, int> m;
		int res = 0;
		for (int i = 0, j = 0; j < (int)s.length(); ++j)
		{
			i = max(i, m[s[j]]);
			m[s[j]] = j + 1;
			res = max(res, j - i + 1);
		}
		return res;
	}
};