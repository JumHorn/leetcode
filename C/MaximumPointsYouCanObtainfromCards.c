
#define max(a, b) (((a) > (b)) ? (a) : (b))

int maxScore(int *cardPoints, int cardPointsSize, int k)
{
	int N = cardPointsSize, sum = 0;
	for (int i = 0; i < k; ++i)
		sum += cardPoints[i];
	int res = sum;
	for (int i = k - 1; i >= 0; --i)
	{
		sum = sum - cardPoints[i] + cardPoints[N - 1 - (k - 1 - i)];
		res = max(res, sum);
	}
	return res;
}