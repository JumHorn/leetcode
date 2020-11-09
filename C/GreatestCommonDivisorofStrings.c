#include <stdbool.h>
#include <string.h>

int gcd(int x, int y)
{
	return x == 0 ? y : gcd(y % x, x);
}

//p / q (q's size is len)
bool divide(char *p, char *q, int len)
{
	for (int i = 0; p[i]; ++i)
	{
		if (p[i] != q[i % len])
			return false;
	}
	return true;
}

char *gcdOfStrings(char *str1, char *str2)
{
	int N1 = strlen(str1), N2 = strlen(str2);
	for (int i = gcd(N1, N2); i > 0; --i)
	{
		if (divide(str1, str1, i) && divide(str2, str1, i))
		{
			str1[i] = '\0';
			return str1;
		}
	}
	return "";
}