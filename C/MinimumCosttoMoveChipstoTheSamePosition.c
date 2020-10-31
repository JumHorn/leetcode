
#define min(a, b) (((a) < (b)) ? (a) : (b))

int minCostToMoveChips(int* position, int positionSize)
{
	int even = 0, odd = 0;
	for (int i = 0; i < positionSize; ++i)
		position[i] % 2 == 0 ? ++even : ++odd;
	return min(even, odd);
}
