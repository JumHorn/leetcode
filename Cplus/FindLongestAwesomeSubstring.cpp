#include <numeric>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int longestAwesome(string s)
	{
		int lo = 2, hi = s.length() + 1;
		while (lo < hi)
		{
			int mi = (hi - lo) / 2 + lo;
			if (slideWindow(s, mi))
				lo = mi + 1;
			else
				hi = mi;
		}
		return lo - 1;
	}

	bool slideWindow(string &s, int len)
	{
		vector<int> v(10);
		for (int i = 0; i < len; ++i)
			v[s[i] - '0'] ^= 1;
		int ones = accumulate(v.begin(), v.end(), 0);
		if (ones <= 1)
			return true;
		for (int i = len; i < (int)s.length(); ++i)
		{
			int index = s[i] - '0';
			v[index] ^= 1;
			ones += v[index] == 1 ? 1 : -1;
			index = s[i - len] - '0';
			v[index] ^= 1;
			ones += v[index] == 1 ? 1 : -1;
			if (ones <= 1)
				return true;
		}
		return false;
	}
};