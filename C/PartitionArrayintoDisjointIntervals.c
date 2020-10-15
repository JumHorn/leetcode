
#define max(a, b) (((a) > (b)) ? (a) : (b))

int partitionDisjoint(int* A, int ASize)
{
	int localMax = A[0], partitionIdx = 0, globalMax = localMax;
	for (int i = 1; i < ASize; i++)
	{
		if (localMax > A[i])
		{
			localMax = globalMax;
			partitionIdx = i;
		}
		else
			globalMax = max(globalMax, A[i]);
	}
	return partitionIdx + 1;
}
