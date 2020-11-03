#include <string.h>

int numTeams(int* rating, int ratingSize)
{
	int dp_up[ratingSize], dp_down[ratingSize], res = 0;
	memset(dp_up, 0, sizeof(dp_up));
	memset(dp_down, 0, sizeof(dp_down));
	for (int i = 1; i < ratingSize; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (rating[j] < rating[i])
			{
				++dp_up[i];
				res += dp_up[j];
			}
			if (rating[j] > rating[i])
			{
				++dp_down[i];
				res += dp_down[j];
			}
		}
	}
	return res;
}
