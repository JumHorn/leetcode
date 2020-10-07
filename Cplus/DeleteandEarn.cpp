#include <map>
#include <vector>
using namespace std;

/*
the following is the evolution of house rob
dp[i]=max(dp[i-1],dp[i-2]+x)
*/

class Solution
{
public:
	int deleteAndEarn(vector<int> &nums)
	{
		int N = nums.size();
		if (nums.empty())
			return 0;
		map<int, int> dp;
		for (auto n : nums)
			dp[n] += n;
		int a = dp.begin()->second, b = 0;
		for (auto iter = ++dp.begin(); iter != dp.end(); ++iter)
		{
			auto pre = iter;
			--pre;
			if (iter->first == pre->first + 1)
			{
				int tmp = max(a, b + iter->second);
				b = a;
				a = tmp;
			}
			else
			{
				b = a;
				a = a + iter->second;
			}
		}
		return a;
	}
};