#include <stdbool.h>

bool canThreePartsEqualSum(int *A, int ASize)
{
	int sum = 0;
	for (int i = 0; i < ASize; ++i)
		sum += A[i];
	if (sum % 3)
		return false;
	sum /= 3;

	int i = 0, part = A[0];
	while (++i < ASize && part != sum)
		part += A[i];
	if (i == ASize || part != sum)
		return false;
	part = A[i];
	while (++i < ASize && part != sum)
		part += A[i];
	return i != ASize && part == sum;
}