#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution
{
public:
	int maxFreq(string s, int maxLetters, int minSize, int maxSize)
	{
		unordered_map<string, int> substrCount;
		unordered_map<char, int> m;
		int res = 0;
		for (int i = 0; i < minSize; ++i)
			++m[s[i]];
		if (m.size() <= maxLetters)
			res = max(res, ++substrCount[s.substr(0, minSize)]);
		for (int i = minSize; i < (int)s.length(); ++i)
		{
			if (--m[s[i - minSize]] == 0)
				m.erase(s[i - minSize]);
			++m[s[i]];
			if (m.size() <= maxLetters)
				res = max(res, ++substrCount[s.substr(i - minSize + 1, minSize)]);
		}
		return res;
	}
};