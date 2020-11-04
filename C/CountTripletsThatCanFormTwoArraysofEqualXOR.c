
int countTriplets(int* arr, int arrSize)
{
	int res = 0;
	for (int i = 0; i < arrSize - 1; ++i)
	{
		int a = 0;
		for (int j = i + 1; j < arrSize; ++j)
		{
			a ^= arr[j - 1];
			int b = 0;
			for (int k = j; k < arrSize; ++k)
			{
				b ^= arr[k];
				if (a == b)
					++res;
			}
		}
	}
	return res;
}
