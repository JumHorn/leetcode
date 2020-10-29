
int peakIndexInMountainArray(int *arr, int arrSize)
{
	int lo = 0, hi = arrSize - 2;
	while (lo < hi)
	{
		int mi = (hi - lo) / 2 + lo;
		if (arr[mi] < arr[mi + 1])
			lo = mi + 1;
		else
			hi = mi;
	}
	return lo;
}