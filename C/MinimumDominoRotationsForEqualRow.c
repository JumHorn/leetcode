#define min(a, b) (((a) < (b)) ? (a) : (b))

bool checkValid(int *A, int *B, int size, int val)
{
	for (int i = 0; i < size; i++)
		if (A[i] != val && B[i] != val)
			return false;
	return true;
}

int minDominoRotations(int *A, int ASize, int *B, int BSize)
{
	int arrA[7] = {0}, arrB[7] = {0};
	for (int i = 0; i < ASize; i++)
	{
		++arrA[A[i]];
		++arrB[B[i]];
	}
	int res = ASize + 5;
	for (int i = 1; i < 7; i++)
	{
		if (arrA[i] + arrB[i] >= ASize && checkValid(A, B, BSize, i))
			res = min(res, min(ASize - arrA[i], ASize - arrB[i]));
	}
	return res >= ASize ? -1 : res;
}