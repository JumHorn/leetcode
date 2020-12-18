#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int characterReplacement(string s, int k)
	{
		int window = 0, maxsame = 0;
		vector<int> hash(26);
		for (int i = 0; i < (int)s.length(); ++i)
		{
			++hash[s[i] - 'A'];
			maxsame = max(maxsame, hash[s[i] - 'A']);
			if (window - maxsame < k)
				++window;
			else
				--hash[s[i - window] - 'A'];
		}
		return window;
	}
};