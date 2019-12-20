

int longestWPI(int *hours, int hoursSize)
{
	int well = 0, i = 0, j = -1, res = 0;
	for (i = 0; i < hoursSize; i++)
	{
		if (hours[i] > 8)
			well += 1;
		else
			well -= 1;
		if (well > 0)
		{
			if (res < i - j)
				res = i - j;
			if (i - j + well - 1 <= hoursSize)
			{
				if (res < i - j + well - 1)
					res = i - j + well - 1;
			}
			else
				return hoursSize;
		}
		else if (well < 0)
		{
			while (well < 0)
			{
				++j;
				if (hours[j] > 8)
					well -= 1;
				else
					well += 1;
			}
		}
	}
	j = hoursSize;
	well = 0;
	for (i = hoursSize - 1; i >= 0; i--)
	{
		if (hours[i] > 8)
			well += 1;
		else
			well -= 1;
		if (well > 0)
		{
			if (res < j - i)
				res = j - i;
			if (j - i + well - 1 < hoursSize)
			{
				if (res < j - i + well - 1)
					res = j - i + well - 1;
			}
			else
				return hoursSize;
		}
		else if (well < 0)
		{
			while (well < 0)
			{
				--j;
				if (hours[j] > 8)
					well -= 1;
				else
					well += 1;
			}
		}
	}
	return res;
}

int main()
{
	int hours[] = {8, 12, 7, 6, 10, 10, 9, 11, 12, 6};
	longestWPI(hours, 10);
	return 0;
}