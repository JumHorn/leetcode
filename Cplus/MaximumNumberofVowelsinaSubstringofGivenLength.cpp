#include <string>
#include <unordered_set>
using namespace std;

class Solution
{
public:
	int maxVowels(string s, int k)
	{
		unordered_set<char> vow = {'a', 'e', 'i', 'o', 'u'};
		int res = 0, n = s.length(), count = 0;
		for (int i = 0; i < k; ++i)
		{
			if (vow.find(s[i]) != vow.end())
				++count;
		}
		if (count > res)
			res = count;
		for (int i = k; i < n; ++i)
		{
			if (vow.find(s[i]) != vow.end())
				++count;
			if (vow.find(s[i - k]) != vow.end())
				--count;
			if (count > res)
				res = count;
		}
		return res;
	}
};
