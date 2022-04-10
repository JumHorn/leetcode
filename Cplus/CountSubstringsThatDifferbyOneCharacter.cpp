#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int countSubstrings(string s, string t)
	{
		int N1 = s.length(), N2 = t.length(), res = 0;
		vector<vector<int>> dp_pre(N1 + 1, vector<int>(N2 + 1));
		for (int i = 0; i < N1; ++i)
		{
			for (int j = 0; j < N2; ++j)
				dp_pre[i + 1][j + 1] = (s[i] == t[j] ? dp_pre[i][j] + 1 : 0);
		}

		vector<vector<int>> dp_next(N1 + 1, vector<int>(N2 + 1));
		for (int i = N1 - 1; i >= 0; --i)
		{
			for (int j = N2 - 1; j >= 0; --j)
				dp_next[i][j] = (s[i] == t[j] ? dp_next[i + 1][j + 1] + 1 : 0);
		}

		for (int i = 0; i < N1; ++i)
		{
			for (int j = 0; j < N2; ++j)
			{
				if (s[i] != t[j])
					res += (dp_pre[i][j] + 1) * (dp_next[i + 1][j + 1] + 1);
			}
		}
		return res;
	}
};