#include <vector>
using namespace std;

class Solution
{
public:
	int maxCompatibilitySum(vector<vector<int>> &students, vector<vector<int>> &mentors)
	{
		vector<int> s, m;
		for (auto &v : students)
		{
			int ans = 0;
			for (int i = 0; i < (int)v.size(); ++i)
				ans |= (v[i] << i);
			s.push_back(ans);
		}
		for (auto &v : mentors)
		{
			int ans = 0;
			for (int i = 0; i < (int)v.size(); ++i)
				ans |= (v[i] << i);
			m.push_back(ans);
		}
		int M = s.size(), mask = (1 << students[0].size()) - 1;
		vector<int> dp(1 << M);
		for (int i = 0; i < M; ++i)
		{
			for (int j = (1 << M) - 1; j >= 0; --j) //mentors already choosed
			{
				for (int k = 0; k < M; ++k)
				{
					if (j & (1 << k))
						continue;
					dp[j | (1 << k)] = max(dp[j | (1 << k)], dp[j] + bitCount((~(s[i] ^ m[k])) & mask));
				}
			}
		}
		return dp.back();
	}

	int bitCount(int n)
	{
		int res = 0;
		for (; n != 0; n &= n - 1)
			++res;
		return res;
	}
};