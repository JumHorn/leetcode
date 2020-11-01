#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	string kthSmallestPath(vector<int> &destination, int k)
	{
		vector<vector<int>> dp(35, vector<int>(35, -1));
		int H = destination[1], V = destination[0];
		string res(H + V, 'H');
		for (int i = 0; i < (int)res.size() && V > 0; ++i)
		{
			if (H == 0)
			{
				res[i] = 'V';
				continue;
			}
			if (k == 0)
			{
				res[i] = 'H';
				--H;
				continue;
			}

			int count = C(H + V - 1, V, dp);
			if (k > count)
			{
				k -= count;
				res[i] = 'V';
				--V;
			}
			else
			{
				--H;
			}
		}
		return res;
	}

	int C(int n, int m, vector<vector<int>> &dp)
	{
		if (m == 0)
			return 0;
		if (m == 1)
			return n;
		if (n == m)
			return 1;
		if (dp[n][m] != -1)
			return dp[n][m];
		return dp[n][m] = C(n - 1, m, dp) + C(n - 1, m - 1, dp);
	}
};