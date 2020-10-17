
/*
slide window
*/

int longestOnes(int* A, int ASize, int K)
{
	int i = 0, j = 0;  //[i,j)
	for (; j < ASize; ++j)
	{
		if (A[j] == 0)
			--K;
		if (K < 0)
			K += 1 ^ A[i++];
	}
	return j - i;
}
