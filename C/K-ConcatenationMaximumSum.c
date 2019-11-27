
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define MOD (int)(1e9 + 7)

int kConcatenationMaxSum(int *arr, int arrSize, int k)
{
	int res = 0;
	long sum = 0;
	if (k == 1)
	{
		for (int i = 0; i < arrSize; i++)
		{
			sum = max(sum + arr[i], arr[i]);
			res = max(res, sum);
		}
		return res % MOD;
	}

	for (int i = 0; i < 2 * arrSize; i++)
	{
		sum = max(sum + arr[i % arrSize], arr[i % arrSize]);
		res = max(res, sum);
	}
	if (k == 2)
		return res % MOD;

	sum = 0;
	for (int i = 0; i < 3 * arrSize; i++)
	{
		sum = max(sum + arr[i % arrSize], arr[i % arrSize]);
		res = max(res, sum);
	}

	sum = 0;
	for (int i = 0; i < arrSize; i++)
		sum += arr[i];
	sum = (max(sum, 0) % MOD) * (k - 2);
	int left = 0, right = 0, all = 0;
	for (int i = 0; i < arrSize; i++)
	{
		all += arr[i];
		left = max(left, all);
	}
	all = 0;
	for (int i = arrSize - 1; i >= 0; i--)
	{
		all += arr[i];
		right = max(right, all);
	}
	res = max(res % MOD, sum % MOD + left % MOD + right % MOD);
	return res % MOD;
}