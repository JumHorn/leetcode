
#define min(a, b) (((a) < (b)) ? (a) : (b))

int minCostClimbingStairs(int* cost, int costSize)
{
	int dp1 = 0, dp2 = 0;
	for (int i = 0; i < costSize; ++i)
	{
		int dp3 = min(dp1, dp2) + cost[i];
		dp1 = dp2;
		dp2 = dp3;
	}
	return min(dp1, dp2);
}
