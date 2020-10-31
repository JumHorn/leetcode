
int findSpecialInteger(int *arr, int arrSize)
{
	for (int i = 1, j = 0; i <= arrSize; ++i)
	{
		if (i == arrSize || arr[i] != arr[j])
		{
			if ((i - j) * 1.0 / arrSize > 0.25)
				return arr[j];
			j = i;
		}
	}
	return 0;
}