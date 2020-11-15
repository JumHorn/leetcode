#include <cstring>
#include <vector>
using namespace std;

class Solution
{
public:
	int getMaxGridHappiness(int m, int n, int introvertsCount, int extrovertsCount)
	{
		// row mask for every 2 bits as a group 00 for no people 01 for introverts 10 for extroverts
		// int dp[3^n][m + 1][introvertsCount][extrovertsCount];
		int dp[243][6][7][7];
		preCalcu(n, cache);
		memset(dp, -1, sizeof(dp));
		return memdp(m, n, 0, 0, introvertsCount, extrovertsCount, dp);
	}

	//row mask for every 2 bits as a group 0 for no people 1 for introverts 2 for extroverts
	int memdp(int M, int N, int mask, int row, int intro, int extro, int (*dp)[6][7][7])
	{
		int pow3[] = {1, 3, 9, 27, 81, 243};
		if (row >= M)
			return 0;
		if (dp[mask][row][intro][extro] != -1)
			return dp[mask][row][intro][extro];
		int res = 0;
		for (int i = 0; i < pow3[N]; ++i)
		{
			int in = cache[mask][i][1], ex = cache[mask][i][2], happy = cache[mask][i][0];
			if (in <= intro && ex <= extro)
				res = max(res, happy + memdp(M, N, i, row + 1, intro - in, extro - ex, dp));
		}
		return dp[mask][row][intro][extro] = res;
	}

	// int cache[243][243][3] pre row,cur row,[happy,intro,extro]
	void preCalcu(int N, int (*cache)[243][3])
	{
		int pow3[] = {1, 3, 9, 27, 81, 243};
		for (int mask = 0; mask < pow3[N]; ++mask)
		{
			for (int i = 0; i < pow3[N]; ++i)
			{
				int in = 0, ex = 0, pre = 0, happy = 0;
				for (int j = 0; j < N; ++j)
				{
					if (i / pow3[j] % 3 == 1) //introvert
					{
						++in;
						happy += 120;
						//inner row
						if (pre == 1)
							happy += -30 - 30;
						else if (pre == 2)
							happy += 20 - 30;
						pre = 1;
						// pre row
						if (mask / pow3[j] % 3 == 1)
							happy += -30 - 30;
						else if (mask / pow3[j] % 3 == 2)
							happy += 20 - 30;
					}
					else if (i / pow3[j] % 3 == 2) //extrovert
					{
						++ex;
						happy += 40;
						//inner row
						if (pre == 0b01)
							happy += 20 - 30;
						else if (pre == 0b10)
							happy += 20 + 20;
						pre = 2;
						// pre row
						if (mask / pow3[j] % 3 == 1)
							happy += 20 - 30;
						else if (mask / pow3[j] % 3 == 2)
							happy += 20 + 20;
					}
					else //no people
						pre = 0;
				}
				cache[mask][i][0] = happy;
				cache[mask][i][1] = in;
				cache[mask][i][2] = ex;
			}
		}
	}

private:
	int cache[243][243][3];
};