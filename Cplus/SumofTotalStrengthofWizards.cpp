#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
	int totalStrength(vector<int> &strength)
	{
		long long N = strength.size(), res = 0;
		vector<long long> left(N, -1), right(N, N), prefixsum(N + 1);
		stack<int> stk; //increasing stack
		for (int i = 0; i < N; ++i)
		{
			while (!stk.empty() && strength[i] < strength[stk.top()])
			{
				right[stk.top()] = i;
				stk.pop();
			}
			stk.push(i);
		}
		stk = stack<int>(); //clear
		for (int i = N - 1; i >= 0; --i)
		{
			while (!stk.empty() && strength[i] <= strength[stk.top()])
			{
				left[stk.top()] = i;
				stk.pop();
			}
			stk.push(i);
		}
		for (int i = 0; i < N; ++i)
			prefixsum[i + 1] = (prefixsum[i] + strength[i]) % MOD;
		for (int i = 0; i < N; ++i)
			prefixsum[i + 1] = (prefixsum[i + 1] + prefixsum[i]) % MOD;
		for (int i = 0; i < N; ++i)
		{
			int l = left[i], ln = i - l, r = right[i], rn = r - i;
			long lacc = (prefixsum[i] - prefixsum[max(l, 0)]) % MOD;
			long racc = (prefixsum[r] - prefixsum[i]) % MOD;
			res = (res + ((racc * ln % MOD - lacc * rn % MOD) * strength[i]) % MOD) % MOD;
		}
		return (res + MOD) % MOD;
	}

private:
	static const int MOD = 1e9 + 7;
};