
#define max(a, b) (((a) > (b)) ? (a) : (b))

int maxTurbulenceSize(int* A, int ASize)
{
	int inc = 1, dec = 1, res = 1;
	for (int i = 1; i < ASize; ++i)
	{
		if (A[i] > A[i - 1])
		{
			inc = dec + 1;
			dec = 1;
			res = max(res, inc);
		}
		else if (A[i] < A[i - 1])
		{
			dec = inc + 1;
			inc = 1;
			res = max(res, dec);
		}
		else
		{
			dec = inc = 1;
		}
	}
	return res;
}
