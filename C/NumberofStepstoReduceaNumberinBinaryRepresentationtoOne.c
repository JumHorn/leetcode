#include <string.h>

int numSteps(char* s)
{
	int res = 0, carry = 0;
	for (int i = strlen(s) - 1; i > 0; --i)
	{
		++res;
		if (s[i] - '0' + carry == 1)
		{
			carry = 1;
			++res;
		}
	}
	return res + carry;
}
