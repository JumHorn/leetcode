
int numOfSubarrays(int* arr, int arrSize)
{
	static const int MOD = 1e9 + 7;
	int odd = arr[0] % 2, even = 1 - odd, res = odd;
	for (int i = 1; i < arrSize; ++i)
	{
		if (arr[i] % 2 == 0)
			++even;
		else
		{
			int next_odd = even + 1;
			even = odd;
			odd = next_odd;
		}
		res = (res + odd) % MOD;
	}
	return res;
}
