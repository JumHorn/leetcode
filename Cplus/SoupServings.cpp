#include <map>
using namespace std;

class Solution
{
public:
	double soupServings(int N)
	{
		if (N >= 5000)
			return 1;
		map<pair<int, int>, double> dp;
		return memdp(N, N, dp);
	}

	double memdp(int A, int B, map<pair<int, int>, double> &dp)
	{
		if (A <= 0 && B <= 0)
			return 0.5;
		if (A <= 0)
			return 1;
		if (B <= 0)
			return 0;
		if (dp.find({A, B}) != dp.end())
			return dp[{A, B}];
		double res = 0;
		for (int i = 0; i <= 75; i += 25)
			res += memdp(A - (100 - i), B - i, dp);
		return dp[{A, B}] = res * 0.25;
	}
};