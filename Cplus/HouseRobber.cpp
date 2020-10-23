#include <vector>
using namespace std;

/*
dp[i]=max(dp[i-1],dp[i-2]+x)
*/

class Solution
{
public:
	int rob(vector<int> &nums)
	{
		int f1 = 0, f2 = 0;
		for (auto n : nums)
		{
			int f3 = max(f2, f1 + n);
			f1 = f2;
			f2 = f3;
		}
		return f2;
	}
};