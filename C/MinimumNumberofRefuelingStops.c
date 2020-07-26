
#define max(a, b) (((a) > (b)) ? (a) : (b))

int minRefuelStops(int target, int startFuel, int** stations, int stationsSize, int* stationsColSize)
{
	long dp[stationsSize + 1];
	for (int i = 0; i <= stationsSize; ++i)
		dp[i] = startFuel;
	for (int i = 0; i < stationsSize; ++i)
	{
		for (int j = i; j >= 0 && dp[j] >= stations[i][0]; --j)
			dp[j + 1] = max(dp[j + 1], dp[j] + stations[i][1]);
	}
	for (int i = 0; i <= stationsSize; ++i)
	{
		if (dp[i] >= target)
			return i;
	}
	return -1;
}
