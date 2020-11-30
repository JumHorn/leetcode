/*
gray code
*/

int minimumOneBitOperations(int n)
{
	int res = 0;
	for (; n != 0; n >>= 1)
		res ^= n;
	return res;
}