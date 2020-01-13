#include <math.h>

int kthGrammar(int N, int K)
{
	int index = pow(2, N) - 1 + K;
	int flag = 0;
	while (index != 1)
	{
		flag += (index & 1);
		index >>= 1;
	}
	return flag % 2;
}

