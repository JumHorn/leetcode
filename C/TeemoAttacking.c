
int findPoisonedDuration(int* timeSeries, int timeSeriesSize, int duration)
{
	int res = 0, poison_lasted = -1;
	for (int i = 0; i < timeSeriesSize; i++)
	{
		if (timeSeries[i] <= poison_lasted)
			res += timeSeries[i] + duration - poison_lasted;
		else
			res += duration;
		poison_lasted = timeSeries[i] + duration;
	}
	return res;
}

