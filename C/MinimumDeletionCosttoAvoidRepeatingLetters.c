
#define max(a, b) (((a) > (b)) ? (a) : (b))

int minCost(char* s, int* cost, int costSize)
{
	int res = 0, sum = cost[0], maxval = cost[0];
	for (int i = 1, j = 0; i <= costSize; ++i)
	{
		if (i == costSize || s[i] != s[j])
		{
			res += sum - maxval;
			j = i;
			if (i < costSize)
				maxval = sum = cost[i];
		}
		else
		{
			sum += cost[i];
			maxval = max(maxval, cost[i]);
		}
	}
	return res;
}
