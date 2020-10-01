#include <string.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

int shoppingOffers(int* price, int priceSize, int** special, int specialSize, int* specialColSize, int* needs, int needsSize)
{
	int res = 0;
	for (int i = 0; i < priceSize; ++i)
		res += needs[i] * price[i];
	for (int i = 0; i < specialSize; ++i)
	{
		int newneeds[needsSize];
		memcpy(newneeds, needs, sizeof(int) * needsSize);
		int j;
		for (j = 0; j < needsSize; ++j)
		{
			newneeds[j] -= special[i][j];
			if (newneeds[j] < 0)
				break;
		}
		if (j == needsSize)
		{
			int val = shoppingOffers(price, priceSize, special, specialSize, specialColSize, newneeds, needsSize);
			res = min(res, val + special[i][specialColSize[i] - 1]);
		}
	}
	return res;
}
