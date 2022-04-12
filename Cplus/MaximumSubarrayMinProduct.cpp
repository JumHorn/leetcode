#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxSumMinProduct(vector<int> &nums)
	{
		long res = 0, N = nums.size();
		vector<long> prefixsum(N + 1);
		for (int i = 0; i < N; ++i)
			prefixsum[i + 1] += prefixsum[i] + nums[i];
		stack<int> stk; //increasing stack
		for (int i = 0; i <= N; ++i)
		{
			while (!stk.empty() && (i == N || nums[stk.top()] > nums[i]))
			{
				int index = stk.top();
				stk.pop();
				int pre = (stk.empty() ? -1 : stk.top());
				res = max(res, (prefixsum[i] - prefixsum[pre + 1]) * nums[index]);
			}
			stk.push(i);
		}
		return res % MOD;
	}

private:
	static const int MOD = 1e9 + 7;
};