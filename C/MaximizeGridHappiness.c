#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

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

int getMaxGridHappiness(int m, int n, int introvertsCount, int extrovertsCount)
{
	// int dp[m + 1][3^n][introvertsCount][extrovertsCount];
	int dp[m + 1][243][7][7], cache[243][243][3];
	int pow3[] = {1, 3, 9, 27, 81, 243};
	preCalcu(n, cache);
	memset(dp, -1, sizeof(dp));
	dp[0][0][0][0] = 0;
	int res = 0;
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < pow3[n]; ++j)
		{
			for (int in = 0; in <= introvertsCount; ++in)
			{
				for (int ex = 0; ex <= extrovertsCount; ++ex)
				{
					if (dp[i][j][in][ex] == -1)
						continue;
					for (int k = 0; k < pow3[n]; ++k)
					{
						int happy = cache[j][k][0], a = cache[j][k][1], b = cache[j][k][2];
						if (a + in > introvertsCount || b + ex > extrovertsCount)
							continue;
						dp[i + 1][k][in + a][ex + b] = max(dp[i + 1][k][in + a][ex + b],
														   dp[i][j][in][ex] + happy);
						res = max(res, dp[i + 1][k][in + a][ex + b]);
					}
				}
			}
		}
	}
	return res;
}