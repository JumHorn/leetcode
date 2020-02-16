#define min(a, b) (((a) < (b)) ? (a) : (b))

int minCostToMoveChips(int* chips, int chipsSize)
{
	int odd = 0, even = 0;
	for (int i = 0; i < chipsSize; i++)
	{
		if (chips[i] % 2 == 0)
			++even;
		else
			++odd;
	}
	return min(even, odd);
}

