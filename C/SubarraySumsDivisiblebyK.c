
int subarraysDivByK(int *A, int ASize, int K)
{
	int hash[10001] = {0};
	int res = 0, sum = 0;
	hash[0] = 1;
	for (int i = 0; i < ASize; ++i)
		A[i] = (A[i] % K + K) % K;
	for (int i = 0; i < ASize; ++i)
	{
		sum += A[i];
		int val = sum % K;
		res += hash[val];
		++hash[val];
	}
	return res;
}