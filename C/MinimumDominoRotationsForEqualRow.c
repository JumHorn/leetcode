
#define max(a, b) (((a) > (b)) ? (a) : (b))

int minDominoRotations(int *A, int ASize, int *B, int BSize)
{
	int countA[7] = {0}, countB[7] = {0}, same[7] = {0};
	for (int i = 0; i < ASize; ++i)
	{
		++countA[A[i]];
		++countB[B[i]];
		if (A[i] == B[i])
			++same[A[i]];
	}
	for (int i = 1; i < 7; ++i)
	{
		if (countA[i] + countB[i] - same[i] == ASize)
			return ASize - max(countA[i], countB[i]);
	}
	return -1;
}