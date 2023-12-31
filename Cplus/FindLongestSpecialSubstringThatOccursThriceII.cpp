#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int maximumLength(string s)
	{
		int N = s.size(), lo = 0, hi = N;
		while (lo < hi)
		{
			int mi = (hi - lo) / 2 + lo;
			if (check(s, mi))
				lo = mi + 1;
			else
				hi = mi;
		}
		return lo - 1;
	}

	bool check(string &s, int len)
	{
		unordered_map<char, int> m; //{char,count}
		vector<int> count(26);		// substr count
		int N = s.size();
		for (int i = 0; i < len; ++i)
			++m[s[i]];
		if (m.size() == 1)
		{
			if (++count[m.begin()->first - 'a'] >= 3)
				return true;
		}
		for (int i = len; i < N; ++i)
		{
			if (--m[s[i - len]] == 0)
				m.erase(s[i - len]);
			++m[s[i]];
			if (m.size() == 1)
			{
				if (++count[m.begin()->first - 'a'] >= 3)
					return true;
			}
		}
		return false;
	}
};