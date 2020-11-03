#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int numSplits(string s)
	{
		vector<int> left(26), right(26);
		for (auto c : s)
			++right[c - 'a'];
		int res = 0, leftcount = 0, rightcount = 0;
		for (int i = 0; i < 26; ++i)
			rightcount += right[i] > 0 ? 1 : 0;
		for (auto c : s)
		{
			if (--right[c - 'a'] == 0)
				--rightcount;
			if (left[c - 'a'] == 0)
				++leftcount;
			++left[c - 'a'];
			if (rightcount == leftcount)
				++res;
		}
		return res;
	}
};
