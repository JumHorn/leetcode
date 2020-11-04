#include <algorithm>
#include <deque>
#include <vector>
using namespace std;

class Solution
{
public:
	int constrainedSubsetSum(vector<int> &nums, int k)
	{
		int N = nums.size();
		vector<int> dp(N);
		deque<int> q;
		dp[0] = nums.front();
		q.push_back(0);
		for (int i = 1; i < N; ++i)
		{
			while (i - q.front() > k)
				q.pop_front();
			dp[i] = nums[i] + (dp[q.front()] < 0 ? 0 : dp[q.front()]);
			while (!q.empty() && dp[i] > dp[q.back()])
				q.pop_back();
			q.push_back(i);
		}
		return *max_element(dp.begin(), dp.end());
	}
};