#include <math.h>
#include <stdbool.h>

int digitsReorder(unsigned int N)
{
	int res = 0;
	for (; N; N /= 10)
		res += pow(10, N % 10);
	return res;
}

bool reorderedPowerOf2(int N)
{
	int d = digitsReorder(N);
	for (int i = 0; i < 32; ++i)
	{
		if (d == digitsReorder(1u << i))
			return true;
	}
	return false;
}
