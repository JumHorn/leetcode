
int candy(int* ratings, int ratingsSize)
{
	if (ratingsSize == 0)
		return 0;
	int candies[ratingsSize], res = 0;
	candies[0] = 1;
	for (int i = 1; i < ratingsSize; ++i)
	{
		if (ratings[i] > ratings[i - 1])
			candies[i] = candies[i - 1] + 1;
		else
			candies[i] = 1;
	}
	res = candies[ratingsSize - 1];
	for (int i = ratingsSize - 2; i >= 0; --i)
	{
		if (ratings[i] > ratings[i + 1] && candies[i] <= candies[i + 1])
			candies[i] = candies[i + 1] + 1;
		res += candies[i];
	}
	return res;
}
