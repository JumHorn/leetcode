#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int bestTeamScore(vector<int> &scores, vector<int> &ages)
	{
		int N = scores.size();
		vector<pair<int, int>> v;
		for (int i = 0; i < N; ++i)
			v.push_back({ages[i], scores[i]});
		sort(v.begin(), v.end());
		vector<int> dp(N + 1);
		for (int i = 0; i < N; ++i)
		{
			dp[i + 1] = v[i].second;
			for (int j = 0; j < i; ++j)
			{
				if ((v[i].first == v[j].first) || (v[i].second > v[j].second))
					dp[i + 1] = max(dp[i + 1], dp[j + 1] + v[i].second);
			}
		}
		return *max_element(dp.begin(), dp.end());
	}
};