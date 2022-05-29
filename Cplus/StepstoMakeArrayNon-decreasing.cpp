#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
	int totalSteps(vector<int> &nums)
	{
		int res = 0, N = nums.size();
		vector<int> dp(N);
		stack<int> stk;
		stk.push(0);
		for (int i = 1; i < N; ++i)
		{
			int cur = 0;
			while (!stk.empty() && nums[stk.top()] <= nums[i])
			{
				cur = max(cur, dp[stk.top()]);
				stk.pop();
			}
			if (!stk.empty())
			{
				dp[i] = cur + 1;
				res = max(res, dp[i]);
			}
			stk.push(i);
		}
		return res;
	}
};