
#define max(a, b) (((a) > (b)) ? (a) : (b))

int longestMountain(int* A, int ASize)
{
	int res = 0, peek;
	for (int i = 1, j = 0; i < ASize;)
	{
		while (i < ASize && A[i] > A[i - 1])  //up
			++i;
		peek = i - 1;						  //peek
		while (i < ASize && A[i] < A[i - 1])  //down
			++i;
		if (i - 1 < ASize && j != peek && i - 1 != peek)
			res = max(res, i - j);
		while (i < ASize && A[i] == A[i - 1])  //skip equal
			++i;
		j = i - 1;
	}
	return res;
}
