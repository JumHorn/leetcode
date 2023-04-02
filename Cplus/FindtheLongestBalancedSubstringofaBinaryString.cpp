#include <string>
using namespace std;

class Solution
{
public:
	int findTheLongestBalancedSubstring(string s)
	{
		int N = s.size();
		for (int i = N / 2; i >= 1; --i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (check(s, j, i))
					return i * 2;
			}
		}
		return 0;
	}

	bool check(string &s, int index, int len)
	{
		int N = s.size();
		if (index + len * 2 > N)
			return false;
		for (int i = index; i < index + len; ++i)
		{
			if (s[i] != '0' || s[i + len] != '1')
				return false;
		}
		return true;
	}
};