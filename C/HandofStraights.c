#include <stdbool.h>
#include <stdlib.h>

//integer cmp function
int cmp(const void *lhs, const void *rhs)
{
	if (*(int *)lhs == *(int *)rhs)
		return 0;
	return *(int *)lhs < *(int *)rhs ? -1 : 1;
}

bool isNStraightHand(int *hand, int handSize, int W)
{
	if (handSize % W != 0)
		return false;
	qsort(hand, handSize, sizeof(int), cmp);
	int arr[handSize][2], arrSize = 0; //{val,count}
	for (int i = 1, j = 0; i <= handSize; ++i)
	{
		if (i == handSize || hand[i] != hand[j])
		{
			arr[arrSize][0] = hand[j];
			arr[arrSize][1] = i - j;
			j = i;
			++arrSize;
		}
	}
	for (int i = 0; i < arrSize; ++i)
	{
		if (arr[i][1] == 0)
			continue;
		int count = arr[i][1];
		if (i + W - 1 >= arrSize)
			return false;
		for (int j = 0; j < W; ++j)
		{
			if (arr[i + j][0] - arr[i][0] != j) //consecutive
				return false;
			arr[i + j][1] -= count;
			if (arr[i + j][1] < 0)
				return false;
		}
	}
	return true;
}