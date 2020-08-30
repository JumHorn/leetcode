#include <vector>
using namespace std;

class Solution
{
public:
	int numOfWays(vector<int> &nums)
	{
		int N = nums.size();
		cache = vector<vector<int>>(N, vector<int>(N));
		return recursive(nums) - 1;
	}

	int recursive(vector<int> &nums)
	{
		int N = nums.size();
		if (N <= 2)
			return 1;
		vector<int> left, right;
		for (int i = 1; i < N; ++i)
			nums[i] > nums[0] ? right.push_back(nums[i]) : left.push_back(nums[i]);
		int l = recursive(left), r = recursive(right);
		long res = combination(N - 1, left.size(), cache);
		return res * l % MOD * r % MOD;
	}

	int combination(int n, int m, vector<vector<int>> &cache)
	{
		if (m >= n || m == 0)
			return 1;
		if (m == 1)
			return n;
		if (cache[n][m] != 0)
			return cache[n][m];
		return cache[n][m] = (combination(n - 1, m, cache) % MOD + combination(n - 1, m - 1, cache) % MOD) % MOD;
	}

private:
	static const int MOD = 1e9 + 7;
	vector<vector<int>> cache;
};