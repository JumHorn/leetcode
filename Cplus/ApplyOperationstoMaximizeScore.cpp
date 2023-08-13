#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
	int maximumScore(vector<int> &nums, int k)
	{
		long long res = 1, N = nums.size();
		vector<pair<long long, int>> v, count;
		for (auto n : nums)
		{
			v.push_back({primeScore(n), n});
			count.push_back({n, 0});
		}
		stack<int> stk; // decresing stack
		for (int i = 0; i <= N; ++i)
		{
			while (!stk.empty() && (i == N || v[stk.top()].first < v[i].first))
			{
				int index = stk.top();
				stk.pop();
				count[index].second = (i - index) * (index - (stk.empty() ? -1 : stk.top()));
			}
			stk.push(i);
		}
		sort(count.begin(), count.end());
		for (int i = N - 1; i >= 0 && k > 0; --i)
		{
			if (k > count[i].second)
			{
				k -= count[i].second;
				res = (res * modPow(count[i].first, count[i].second)) % MOD;
			}
			else
			{
				res = (res * modPow(count[i].first, k)) % MOD;
				k = 0;
			}
		}
		return res;
	}

	int primeScore(int n)
	{
		int res = 0;
		if (n == 1)
			return 0;
		if (n <= 3)
			return 1;
		for (int i = 2; i * i <= n; ++i)
		{
			if (n % i == 0)
			{
				++res;
				while (n != 0 && n % i == 0)
					n /= i;
			}
		}
		return res + (n > 1 ? 1 : 0);
	}

	long long modPow(long long x, int n)
	{
		long long res = 1;
		for (int i = n; i > 0; i /= 2)
		{
			if (i % 2)
				res = res * x % MOD;
			x = x * x % MOD;
		}
		return res;
	}

private:
	static const int MOD = 1e9 + 7;
};