
#define max(a, b) (((a) > (b)) ? (a) : (b))

int longestSubsequence(int* arr, int arrSize, int difference)
{
	int hash[40001] = {0}, res = 0;
	for (int i = 0; i < arrSize; ++i)
	{
		int n = arr[i] + 20000;
		hash[n] = hash[n - difference] + 1;
		res = max(res, hash[n]);
	}
	return res;
}
