
int countTriplets(int* arr, int arrSize)
{
	int prefix[arrSize + 1], res = 0;
	prefix[0] = 0;
	for (int i = 0; i < arrSize; ++i)
		prefix[i + 1] = prefix[i] ^ arr[i];
	for (int i = 0; i <= arrSize; ++i)
	{
		for (int j = i + 1; j <= arrSize; ++j)
		{
			if (prefix[i] == prefix[j])
				res += j - i - 1;
		}
	}
	return res;
}
