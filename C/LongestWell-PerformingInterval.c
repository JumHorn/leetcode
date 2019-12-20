#define max(a, b) (((a) > (b)) ? (a) : (b))

int longestWPI(int *hours, int hoursSize)
{
	for (int i = 0; i < hoursSize; i++)
	{
		if (hours[i] > 8)
			hours[i] = 1;
		else
			hours[i] = -1;
	}
	for (int i = 1; i < hoursSize; i++)
		hours[i] += hours[i - 1];
	int res = 0;
	for (int i = 0; i < hoursSize; i++)
	{
		if (hours[i] > 0)
		{
			res = max(res, i + 1);
			continue;
		}
		for (int j = 0; j < i; j++)
		{
			if (res > i - j)
				break;
			if (hours[i] - hours[j] > 0)
			{
				res = i - j;
				break;
			}
		}
	}
	return res;
}

