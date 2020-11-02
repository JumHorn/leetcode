
int findKthPositive(int* arr, int arrSize, int k)
{
	int lo = 0, hi = arrSize;
	while (lo < hi)
	{
		int mi = (hi - lo) / 2 + lo;
		if (arr[mi] - mi - 1 < k)
			lo = mi + 1;
		else
			hi = mi;
	}
	if (--lo < 0)
		return k;
	return arr[lo] + k - (arr[lo] - lo - 1);
}
