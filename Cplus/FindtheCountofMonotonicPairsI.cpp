#include <vector>
using namespace std;

class Solution
{
public:
	int countOfPairs(vector<int> &nums)
	{
		int N = nums.size();
		vector<vector<int>> dp(N, vector<int>(51, -1));
		return memdp(nums, 0, -1, dp);
	}

	int memdp(vector<int> &nums, int index, int val1, vector<vector<int>> &dp)
	{
		int res = 0, N = nums.size();
		if (index >= N)
			return 1;
		int val2 = 0;
		if (val1 == -1) // 特殊处理
		{
			val1 = 0;
			val2 = 50;
		}
		else
			val2 = nums[index - 1] - val1;
		if (dp[index][val1] != -1)
			return dp[index][val1];
		for (int i = 0; i <= nums[index]; ++i)
		{
			int j = nums[index] - i;
			if (i >= val1 && j <= val2)
			{
				int r = memdp(nums, index + 1, i, dp);
				res = (res + r) % MOD;
			}
		}
		return dp[index][val1] = res;
	}

private:
	static const int MOD = 1e9 + 7;
};