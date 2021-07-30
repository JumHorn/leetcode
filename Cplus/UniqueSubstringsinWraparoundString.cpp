#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int findSubstringInWraproundString(string p)
	{
		if (p.empty())
			return 0;
		vector<int> dp(26);
		int count, next = -1;
		for (int i = (int)p.size() - 1; i >= 0; --i)
		{
			if ((p[i] - 'a' + 1) % 26 == next)
				++count;
			else
				count = 1;
			dp[p[i] - 'a'] = max(dp[p[i] - 'a'], count);
			next = p[i] - 'a';
		}
		return accumulate(dp.begin(), dp.end(), 0);
	}
};