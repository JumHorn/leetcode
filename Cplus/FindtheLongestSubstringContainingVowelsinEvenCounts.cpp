#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution
{
public:
	int findTheLongestSubstring(string s)
	{
		int mask = 0, res = 0;
		unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
		unordered_map<int, int> m = {{0, -1}}; //{mask,index}
		for (int i = 0; i < (int)s.length(); ++i)
		{
			if (vowels.find(s[i]) != vowels.end())
			{
				mask ^= 1 << (s[i] - 'a');
				m.insert({mask, i});
			}
			res = max(res, i - m[mask]);
		}
		return res;
	}
};