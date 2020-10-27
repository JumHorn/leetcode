
int numOfSubarrays(int* arr, int arrSize, int k, int threshold)
{
	int sum = 0, res = 0, i = 0;
	threshold *= k;
	for (i = 0; i < k; ++i)
		sum += arr[i];
	if (sum >= threshold)
		++res;
	for (i = k; i < arrSize; ++i)
	{
		sum += arr[i] - arr[i - k];
		if (sum >= threshold)
			++res;
	}
	return res;
}
