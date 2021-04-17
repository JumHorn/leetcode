#include <vector>
using namespace std;

class Solution
{
public:
	int numOfWays(vector<int> &nums)
	{
		int N = nums.size();
		//combination table
		vector<vector<int>> combination(N + 1, vector<int>(N + 1));
		combination[0][0] = 1;
		for (int i = 1; i <= N; ++i)
		{
			combination[i][0] = 1;
			for (int j = 1; j <= i; ++j)
				combination[i][j] = combination[i][i - j] = (combination[i - 1][j] + combination[i - 1][j - 1]) % MOD;
		}
		return recursive(nums, combination) - 1;
	}

	int recursive(vector<int> &nums, vector<vector<int>> &cache)
	{
		int N = nums.size();
		if (N <= 2)
			return 1;
		vector<int> left, right;
		for (int i = 1; i < N; ++i)
			nums[i] > nums[0] ? right.push_back(nums[i]) : left.push_back(nums[i]);
		int l = recursive(left, cache), r = recursive(right, cache);
		long res = cache[N - 1][left.size()];
		return res * l % MOD * r % MOD;
	}

private:
	static const int MOD = 1e9 + 7;
};