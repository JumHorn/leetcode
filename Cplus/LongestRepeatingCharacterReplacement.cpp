#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int characterReplacement(string s, int k)
	{
		int i = 0, j = 0, maxsame = 0;
		vector<int> hash(26);
		for (; j < (int)s.length(); ++j)
		{
			++hash[s[j] - 'A'];
			maxsame = max(maxsame, hash[s[j] - 'A']);
			if (j - i - maxsame >= k)
				--hash[s[i++] - 'A'];
		}
		return j - i;
	}
};