#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;

class Solution
{
public:
	int maxVowels(string s, int k)
	{
		unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
		int res = 0, count = 0, N = s.length();
		for (int i = 0; i < N; ++i)
		{
			if (vowels.find(s[i]) != vowels.end())
				++count;
			if (i >= k && vowels.find(s[i - k]) != vowels.end())
				--count;
			res = max(res, count);
		}
		return res;
	}
};