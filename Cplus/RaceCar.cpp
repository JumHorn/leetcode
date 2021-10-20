#include <algorithm>
#include <cmath>
using namespace std;

class Solution
{
public:
	int racecar(int target)
	{
		if (dp[target] > 0)
			return dp[target];
		int n = floor(log2(target)) + 1;
		if ((1 << n) - 1 == target)
			dp[target] = n; //一直加速正好到达终点
		else
		{
			dp[target] = racecar(((1 << n) - 1) - target) + n + 1; //执行n次加速超过终点后返回，1表示R操作
			//表示n-1次加速后R操作返回,往回走i次加速，1次R转向
			for (int i = 0; i < n - 1; ++i)
				dp[target] = min(dp[target], racecar(target - (1 << (n - 1)) + (1 << i)) + n - 1 + i + 1 + 1);
		}
		return dp[target];
	}

private:
	int dp[10001]; //all object use the same data
};