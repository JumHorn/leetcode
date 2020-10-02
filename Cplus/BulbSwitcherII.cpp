#include <unordered_set>
#include <vector>
using namespace std;

/*
the first 6 bulb is the period
all the bulb after the first 6 will be the same state as the first 6 bulb
*/

class Solution
{
public:
	int flipLights(int n, int m)
	{
		vector<unordered_set<int>> dp(m + 1);
		n = min(n, 6);
		memdp((1 << n) - 1, m, (1 << n) - 1, dp);
		return dp[0].size();
	}

	void memdp(int mask, int m, int state, vector<unordered_set<int>> &dp)
	{
		if (m <= 0)
		{
			dp[0].insert(state);
			return;
		}
		if (dp[m].find(state) != dp[m].end())
			return;
		dp[m].insert(state);
		memdp(mask, m - 1, (~state) & mask, dp);		   //1. Flip all the lights.
		memdp(mask, m - 1, (state ^ 0b101010) & mask, dp); //2. Flip lights with even numbers.
		memdp(mask, m - 1, (state ^ 0b010101) & mask, dp); //3. Flip lights with odd numbers.
		memdp(mask, m - 1, (state ^ 0b001001) & mask, dp); //4. Flip lights with (3k + 1) numbers
	}
};