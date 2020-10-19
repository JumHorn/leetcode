
#define max(a, b) (((a) > (b)) ? (a) : (b))

int maxSatisfied(int* customers, int customersSize, int* grumpy, int grumpySize, int X)
{
	int satisfied = 0;
	for (int i = 0; i < customersSize; ++i)
	{
		if (grumpy[i] == 0)
			satisfied += customers[i];
	}
	int res = 0;
	for (int i = 0; i < customersSize; ++i)
	{
		if (i >= X)
		{
			if (grumpy[i - X] == 1)
				satisfied -= customers[i - X];
		}
		if (grumpy[i] == 1)
			satisfied += customers[i];
		res = max(res, satisfied);
	}
	return res;
}
