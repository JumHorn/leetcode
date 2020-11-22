#include <vector>
using namespace std;

class Solution
{
public:
	int waysToMakeFair(vector<int> &nums)
	{
		int odd = 0, even = 0, N = nums.size(), res = 0;
		vector<vector<int>> suffix(N + 1, vector<int>(2)); //odd,even
		for (int i = N - 1; i >= 0; --i)
		{
			if (i % 2 == 1)
			{
				suffix[i][0] += suffix[i + 1][0] + nums[i];
				suffix[i][1] = suffix[i + 1][1];
			}
			else
			{
				suffix[i][1] += suffix[i + 1][1] + nums[i];
				suffix[i][0] = suffix[i + 1][0];
			}
		}

		for (int i = 0; i < N; ++i)
		{
			if (odd + suffix[i + 1][1] == even + suffix[i + 1][0])
				++res;

			if (i % 2 == 1)
				odd += nums[i];
			else
				even += nums[i];
		}
		return res;
	}
};