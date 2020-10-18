
#define max(a, b) (((a) > (b)) ? (a) : (b))

int maxSumTwoNoOverlap(int* A, int ASize, int L, int M)
{
	for (int i = 1; i < ASize; ++i)
		A[i] += A[i - 1];
	int res = A[L + M - 1], maxL = A[L - 1], maxM = A[M - 1];
	for (int i = L + M; i < ASize; ++i)
	{
		maxL = max(maxL, A[i - M] - A[i - L - M]);
		maxM = max(maxM, A[i - L] - A[i - L - M]);
		res = max(res, max(maxL + A[i] - A[i - M], maxM + A[i] - A[i - L]));
	}
	return res;
}
