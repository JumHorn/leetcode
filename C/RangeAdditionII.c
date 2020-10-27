
#define min(a, b) (((a) < (b)) ? (a) : (b))

int maxCount(int m, int n, int** ops, int opsSize, int* opsColSize)
{
	int x = m, y = n;
	for (int i = 0; i < opsSize; ++i)
	{
		x = min(x, ops[i][0]);
		y = min(y, ops[i][1]);
	}
	return x * y;
}
