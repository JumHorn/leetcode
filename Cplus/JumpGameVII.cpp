#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	bool canReach(string s, int minJump, int maxJump)
	{
		int N = s.length(), count = 0;
		if (s.back() == '1')
			return false;
		vector<int> dp(N);
		dp[0] = 1;
		for (int i = minJump; i < N; ++i)
		{
			if (i >= maxJump + 1)
				count -= dp[i - maxJump - 1];
			if (i >= minJump)
				count += dp[i - minJump];
			if (s[i] == '0')
				dp[i] = (count == 0 ? 0 : 1);
		}
		return dp.back() != 0;
	}
};