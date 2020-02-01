

int findSpecialInteger(int* arr, int arrSize)
{
	int i, j;
	for (i = 1, j = 0; i < arrSize; i++)
	{
		if (arr[i] != arr[j])
		{
			if ((i - j) * 1.0 / arrSize > 0.25)
				return arr[j];
			j = i;
		}
	}
	return arr[j];
}

