#include <stdlib.h>
#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

void reverse(char *arr, int first, int last)
{
	for (; first < last; ++first, --last)
	{
		char tmp = arr[first];
		arr[first] = arr[last];
		arr[last] = tmp;
	}
}

char *addStrings(char *num1, char *num2)
{
	int N1 = strlen(num1), N2 = strlen(num2), carry = 0, resSize = 0;
	char *res = (char *)malloc(sizeof(char) * max(N1, N2) + 2);
	for (int i = N1 - 1, j = N2 - 1; i >= 0 || j >= 0 || carry > 0;)
	{
		if (i >= 0)
			carry += num1[i--] - '0';
		if (j >= 0)
			carry += num2[j--] - '0';
		res[resSize++] = carry % 10 + '0';
		carry /= 10;
	}
	res[resSize] = '\0';
	reverse(res, 0, resSize - 1);
	return res;
}