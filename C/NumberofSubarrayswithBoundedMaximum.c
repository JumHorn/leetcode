/*
count the number of subarray ending with A[i]
*/

int numSubarrayBoundedMax(int* A, int ASize, int L, int R)
{
	int l = -1, r = -1, res = 0;
	for (int i = 0; i < ASize; ++i)
	{
		if (A[i] > R)
			l = i;
		if (A[i] >= L)
			r = i;
		res += r - l;
	}
	return res;
}
