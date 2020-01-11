
bool isIdealPermutation(int* A, int ASize)
{
	if (ASize < 3)
		return true;
	int max = A[0];
	for (int i = 2; i < ASize; i++)
	{
		if (A[i - 1] <= A[i - 2])
		{
			max = A[i - 2];
			if (A[i] <= A[i - 2])
				return false;
		}
		else
		{
			if (A[i] < max)
				return false;
			max = A[i - 1];
		}
	}
	return true;
}

