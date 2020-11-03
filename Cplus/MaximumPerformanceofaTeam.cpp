#include <algorithm>
#include <climits>
#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxPerformance(int n, vector<int> &speed, vector<int> &efficiency, int k)
	{
		vector<vector<int>> v;
		for (int i = 0; i < n; ++i)
			v.push_back({efficiency[i], speed[i]});
		sort(v.begin(), v.end(), greater<vector<int>>());
		long long res = 0, sum = 0;
		priority_queue<int> q;
		for (int i = 0; i < n; ++i)
		{
			q.push(-v[i][1]);
			sum += v[i][1];
			if ((int)q.size() > k)
			{
				sum += q.top();
				q.pop();
			}
			res = max(res, v[i][0] * sum);
		}
		return res % MOD;
	}

private:
	static const int MOD = 1e9 + 7;
};