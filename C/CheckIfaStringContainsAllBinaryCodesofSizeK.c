#include <stdbool.h>
#include <string.h>

bool hasAllCodes(char* s, int k)
{
	int N = strlen(s);
	if (k >= N)
		return false;
	unsigned int num = 0;
	int code[1 << k], count = 0;
	memset(code, 0, sizeof(code));
	for (int i = 0; i < k; ++i)
	{
		num <<= 1;
		if (s[i] == '1')
			num |= 1;
	}
	code[num] = 1;
	++count;
	for (int i = k; s[i]; ++i)
	{
		num <<= 1;
		if (s[i] == '1')
			num |= 1;
		int index = (num & ((1 << k) - 1));
		if (code[index] == 0)
		{
			code[index] = 1;
			++count;
		}
	}
	return count >= (1 << k);
}
