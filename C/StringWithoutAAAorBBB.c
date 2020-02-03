#include <stdlib.h>

char* createStr(char a, int A, char b, int B)
{
	char* res = (char*)malloc(sizeof(char) * (A + B + 1));
	res[A + B] = '\0';
	int index = 0;
	while (A != 0 && B != 0)
	{
		if (A != B)
		{
			res[index++] = a;
			res[index++] = a;
			res[index++] = b;
			A -= 2;
			B -= 1;
		}
		else
		{
			res[index++] = a;
			res[index++] = b;
			A -= 1;
			B -= 1;
		}
	}
	while (A != 0)
	{
		res[index++] = a;
		A--;
	}
	while (B != 0)
	{
		res[index++] = b;
		B--;
	}
	return res;
}

char* strWithout3a3b(int A, int B)
{
	char* res;
	if (A > B)
		res = createStr('a', A, 'b', B);
	else
		res = createStr('b', B, 'a', A);
	return res;
}

