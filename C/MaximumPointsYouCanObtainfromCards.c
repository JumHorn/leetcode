
#define max(a, b) (((a) > (b)) ? (a) : (b))

int maxScore(int* cardPoints, int cardPointsSize, int k)
{
	int N = cardPointsSize;
	int prefixsum[N + 1];
	prefixsum[0] = 0;
	for (int i = 0; i < N; ++i)
		prefixsum[i + 1] = prefixsum[i] + cardPoints[i];
	int res = 0;
	for (int i = 0; i <= k; ++i)
		res = max(res, prefixsum[i] + (prefixsum[N] - prefixsum[N - (k - i)]));
	return res;
}
