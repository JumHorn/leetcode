#include <string.h>

int factorial(int n)
{
	if (n < 2)
		return n;
	return factorial(n - 1) * n;
}

char* getPermutation(int n, int k)
{
	char* res = strdup("123456789");
	res[n] = '\0';
	int f = factorial(n);
	--k;  //become zero index
	for (int i = 0; i < n; ++i)
	{
		f /= n - i;
		int j = i + k / f;  // calculate index of char to put at s[i]
		k %= f;
		char c = res[j];
		// remove c by shifting to cover up (adjust the right part).
		for (; j > i; --j)
			res[j] = res[j - 1];
		res[i] = c;
	}
	return res;
}
