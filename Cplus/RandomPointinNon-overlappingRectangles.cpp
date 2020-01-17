#include <cmath>
#include <vector>
using namespace std;

class Solution
{
public:
	Solution(vector<vector<int>> &rects) : dp(rects.size()), m_rects(rects)
	{
		for (int i = 0; i < (int)dp.size(); i++)
			dp[i] = (rects[i][3] - rects[i][1] + 1) * (rects[i][2] - rects[i][0] + 1);
		for (int i = 1; i < (int)dp.size(); i++)
			dp[i] += dp[i - 1];
		maxpoint = dp.back();
	}

	vector<int> pick()
	{
		int tmp = rand() % maxpoint, lo = 0, hi = m_rects.size() - 1, mi;
		if (tmp < dp[0])
			return {m_rects[0][0] + tmp % (m_rects[0][2] - m_rects[0][0] + 1), m_rects[0][1] + tmp / (m_rects[0][2] - m_rects[0][0] + 1)};
		while (lo < hi)
		{
			mi = (hi - lo) / 2 + lo;
			if (dp[mi] <= tmp)
				lo = mi + 1;
			else
				hi = mi;
		}
		tmp -= dp[lo - 1];
		return {m_rects[lo][0] + tmp % (m_rects[lo][2] - m_rects[lo][0] + 1), m_rects[lo][1] + tmp / (m_rects[lo][2] - m_rects[lo][0] + 1)};
	}

private:
	vector<int> dp;
	vector<vector<int>> m_rects;
	int maxpoint;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */