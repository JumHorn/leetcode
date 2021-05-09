#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxSumMinProduct(vector<int> &nums)
	{
		long res = 0, N = nums.size();
		vector<long> prefixsum(N + 1), prev(N), next(N);
		for (int i = 0; i < N; ++i)
			prefixsum[i + 1] += prefixsum[i] + nums[i];
		// same code area
		{ //prev
			stack<int> stk;
			for (int i = 0; i < N; ++i)
			{
				while (!stk.empty() && nums[stk.top()] >= nums[i])
					stk.pop();
				prev[i] = stk.empty() ? -1 : stk.top();
				stk.push(i);
			}
		}
		{ // next
			stack<int> stk;
			for (int i = N - 1; i >= 0; --i)
			{
				while (!stk.empty() && nums[stk.top()] >= nums[i])
					stk.pop();
				next[i] = stk.empty() ? N : stk.top();
				stk.push(i);
			}
		}
		for (int i = 0; i < N; ++i)
			res = max(res, (prefixsum[next[i]] - prefixsum[prev[i] + 1]) * nums[i]);
		return res % MOD;
	}

private:
	static const int MOD = 1e9 + 7;
};