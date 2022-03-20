
#define max(a, b) (((a) > (b)) ? (a) : (b))

int maxWidthRamp(int *A, int ASize)
{
	int res = 0, stack[ASize], top = 0; //store index of A as decreasing stack
	stack[top] = 0;
	for (int i = 1; i < ASize; ++i)
	{
		if (A[i] < A[stack[top]])
			stack[++top] = i;
	}
	for (int i = ASize - 1; i >= 0; --i)
	{
		while (top != -1 && A[i] >= A[stack[top]])
			--top;
		res = max(res, i - stack[top + 1]);
	}
	return res;
}