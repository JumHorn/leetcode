
#define max(a, b) (((a) > (b)) ? (a) : (b))

int longestWPI(int *hours, int hoursSize)
{
	int prefixsum[hoursSize + 1];
	for (int i = 0; i < hoursSize; ++i)
		prefixsum[i + 1] = prefixsum[i] + (hours[i] > 8 ? 1 : -1);
	int stack[hoursSize + 1], top = -1; //decreasing stack with value's index
	stack[++top] = 0;
	for (int i = 0; i <= hoursSize; ++i)
	{
		if (prefixsum[i] < prefixsum[stack[top]])
			stack[++top] = i;
	}
	int res = 0;
	for (int i = hoursSize; i >= 0; --i)
	{
		while (top != -1 && prefixsum[i] - prefixsum[stack[top]] >= 1)
		{
			res = max(res, i - stack[top]);
			--top;
		}
	}
	return res;
}