#include <cstring>
#include <vector>
using namespace std;

class Solution
{
public:
	int getMaxGridHappiness(int m, int n, int introvertsCount, int extrovertsCount)
	{
		// row mask for every 2 bits as a group 00 for no people 01 for introverts 10 for extroverts
		// int dp[1 << (2 * n)][m + 1][introvertsCount][extrovertsCount];
		int dp[1 << 10][6][7][7];
		memset(dp, -1, sizeof(dp));
		return memdp(m, n, 0, 0, introvertsCount, extrovertsCount, dp);
	}

	//row mask for every 2 bits as a group 00 for no people 01 for introverts 10 for extroverts
	int memdp(int M, int N, int mask, int row, int intro, int extro, int (*dp)[6][7][7])
	{
		if (row >= M)
			return 0;
		if (dp[mask][row][intro][extro] != -1)
			return dp[mask][row][intro][extro];
		int res = 0;
		for (int i = 0; i < 1u << (2 * N); ++i)
		{
			int in = 0, ex = 0, pre = 0, happy = 0;
			for (int j = 0; j < N; ++j)
			{
				if (((i >> (2 * j)) & 0b11) == 0b01) //introvert
				{
					++in;
					happy += 120;
					//inner row
					if (pre == 0b01)
						happy += -30 - 30;
					else if (pre == 0b10)
						happy += 20 - 30;
					pre = 0b01;
					// pre row
					if (((mask >> (2 * j)) & 0b11) == 0b01)
						happy += -30 - 30;
					else if (((mask >> (2 * j)) & 0b11) == 0b10)
						happy += 20 - 30;
				}
				else if (((i >> (2 * j)) & 0b11) == 0b10) //extrovert
				{
					++ex;
					happy += 40;
					//inner row
					if (pre == 0b01)
						happy += 20 - 30;
					else if (pre == 0b10)
						happy += 20 + 20;
					pre = 0b10;
					// pre row
					if (((mask >> (2 * j)) & 0b11) == 0b01)
						happy += 20 - 30;
					else if (((mask >> (2 * j)) & 0b11) == 0b10)
						happy += 20 + 20;
				}
				else //no people
					pre = 0;
			}
			if (in <= intro && ex <= extro)
				res = max(res, happy + memdp(M, N, i, row + 1, intro - in, extro - ex, dp));
		}
		return dp[mask][row][intro][extro] = res;
	}
};