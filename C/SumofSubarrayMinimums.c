
int sumSubarrayMins(int* A, int ASize)
{
	static const int MOD = 1e9 + 7;
	int stack[ASize], top = -1;  //increase stack storing index
	int res = 0;
	for (int i = 0; i <= ASize; ++i)
	{
		while (top != -1 && (i == ASize || A[stack[top]] > A[i]))
		{
			int index = stack[top--];
			int j = top == -1 ? -1 : stack[top];
			res = (res + (i - index) * (index - j) * A[index]) % MOD;
		}
		stack[++top] = i;
	}
	return res;
}
