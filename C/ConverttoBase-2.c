#include <stdlib.h>
#include <string.h>

char *baseNeg2(int N)
{
	char source[32] = {0}, nega[32] = {0};
	for (int i = 0; i < 32; i++)
	{
		if (N & (1u << i))
		{
			if (i % 2 == 1)
				nega[30 - i] = 1;
			source[31 - i] = 1;
		}
	}
	int carry = 0;
	for (int i = 31; i >= 0; i--)
	{
		int tmp = carry + source[i] + nega[i];
		if (tmp > 1)
		{
			tmp = 0;
			source[i] = '0';
			--i;
			carry = source[i] ? 0 : 1;
			source[i] = 1 - source[i];
			source[i] += '0';
		}
		else
		{
			carry = 0;
			source[i] = tmp ? '1' : '0';
		}
	}
	int index = 0;
	while (index < 31 && source[index] == '0')
		++index;
	char *res = (char *)malloc((31 - index + 2) * sizeof(int));
	memcpy(res, source + index, 31 - index + 1);
	res[31 - index + 1] = '\0';
	return res;
}