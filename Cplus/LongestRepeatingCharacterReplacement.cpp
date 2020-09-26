#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int characterReplacement(string s, int k)
	{
		int window = 0, maxcount = 0;
		vector<int> hash(26);
		for (int i = 0; i < (int)s.length(); ++i)
		{
			++hash[s[i] - 'A'];
			maxcount = max(hash[s[i] - 'A'], maxcount);
			if (window - maxcount < k)
				++window;
			else
				--hash[s[i - window] - 'A'];
		}
		return window;
	}
};