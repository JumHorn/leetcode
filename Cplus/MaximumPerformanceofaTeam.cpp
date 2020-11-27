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
		vector<pair<int, int>> v;
		for (int i = 0; i < n; ++i)
			v.emplace_back(efficiency[i], speed[i]);
		sort(v.begin(), v.end(), greater<pair<int, int>>());
		long res = 0, sum = 0;
		priority_queue<int, vector<int>, greater<int>> q;
		for (auto &[e, s] : v)
		{
			q.push(s);
			sum += s;
			if ((int)q.size() > k)
			{
				sum -= q.top();
				q.pop();
			}
			res = max(res, e * sum);
		}
		return res % MOD;
	}

private:
	static const int MOD = 1e9 + 7;
};