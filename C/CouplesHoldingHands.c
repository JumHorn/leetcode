#include <stdlib.h>

#define swap(a, b) ((a) != (b) && ((a) ^= (b) ^= (a) ^= (b)))

int minSwapsCouples(int *row, int rowSize)
{
	int res = 0, couple[rowSize], pos[rowSize];
	for (int i = 0; i < rowSize; ++i)
	{
		couple[i] = (i % 2 == 0 ? i + 1 : i - 1);
		pos[row[i]] = i;
	}

	for (int i = 0; i < rowSize; ++i)
	{
		for (int j = couple[pos[couple[row[i]]]]; i != j; j = couple[pos[couple[row[i]]]])
		{
			swap(row[i], row[j]);
			swap(pos[row[i]], pos[row[j]]);
			++res;
		}
	}
	return res;
}