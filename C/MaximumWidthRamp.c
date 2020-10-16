
#define max(a, b) (((a) > (b)) ? (a) : (b))

int maxWidthRamp(int *A, int ASize)
{
	int res = 0, stack[ASize], top = 0; //store index of A as decreasing stack
	stack[top] = 0;
	for (int i = 1; i < ASize; ++i)
	{
		if (A[i] < A[stack[top]])
			stack[++top] = i;
		else if (A[i] >= A[0])
			res = max(res, i - 0);
		else
		{
			int lo = 0, hi = top;
			while (lo < hi)
			{
				int mi = (hi - lo) / 2 + lo;
				if (A[stack[mi]] > A[i])
					lo = mi + 1;
				else
					hi = mi;
			}
			res = max(res, i - stack[lo]);
		}
	}
	return res;
}