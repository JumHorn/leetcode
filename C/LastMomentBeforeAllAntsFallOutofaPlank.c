
#define max(a, b) (((a) > (b)) ? (a) : (b))

int getLastMoment(int n, int* left, int leftSize, int* right, int rightSize)
{
	int res = 0;
	for (int i = 0; i < leftSize; ++i)
		res = max(res, left[i]);
	for (int i = 0; i < rightSize; ++i)
		res = max(res, n - right[i]);
	return res;
}
