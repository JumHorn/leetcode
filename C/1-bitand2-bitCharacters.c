#include <stdbool.h>

bool isOneBitCharacter(int* bits, int bitsSize)
{
	if (bitsSize == 0)
		return false;
	if (bitsSize == 1 || bits[bitsSize - 1] == 1)
		return bits[0] == 0;
	int one = 0;
	for (int i = bitsSize - 2; i >= 0 && bits[i] == 1; --i)
		++one;
	return one % 2 == 0;
}
