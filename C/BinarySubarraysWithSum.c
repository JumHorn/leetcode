/*
slide window
add all subarray which end with i,when i updated
*/

#define max(a, b) (((a) > (b)) ? (a) : (b))

int numSubarraysWithSum(int *A, int ASize, int S)
{
	int res = 0, sum = 0;
	for (int i = 0, j = 0, k = 0; i < ASize; ++i)
	{
		sum += A[i];
		for (; j < i && sum > S; ++j)
			sum -= A[j];
		if (sum == S)
		{
			k = max(k, j);
			while (k < i && A[k] == 0)
				++k;
			res += k - j + 1;
		}
	}
	return res;
}