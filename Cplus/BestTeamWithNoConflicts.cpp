#include <algorithm>
#include <functional>
#include <vector>
using namespace std;

class Solution
{
public:
	int bestTeamScore(vector<int> &scores, vector<int> &ages)
	{
		int N = scores.size(), res = 0;
		vector<pair<int, int>> v;
		for (int i = 0; i < N; ++i)
			v.push_back({ages[i], scores[i]});
		sort(v.begin(), v.end(), greater<>());
		vector<int> dp(N);
		for (int i = 0; i < N; ++i)
		{
			dp[i] = v[i].second;
			for (int j = 0; j < i; ++j)
			{
				if (v[i].second <= v[j].second)
					dp[i] = max(dp[i], dp[j] + v[i].second);
			}
			res = max(res, dp[i]);
		}
		return res;
	}
};