#include <stdlib.h>
#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

void reverse(char* arr, int first, int last)
{
	while (first < last)
	{
		char tmp = arr[first];
		arr[first] = arr[last];
		arr[last] = tmp;
		++first;
		--last;
	}
}

char* addBinary(char* a, char* b)
{
	int i = strlen(a), j = strlen(b), resSize = 0, carry = 0;
	char* res = (char*)malloc(sizeof(char) * (max(i, j) + 2));
	for (--i, --j; i >= 0 || j >= 0 || carry > 0;)
	{
		if (i >= 0)
			carry += a[i--] - '0';
		if (j >= 0)
			carry += b[j--] - '0';
		res[resSize++] = carry % 2 + '0';
		carry /= 2;
	}
	reverse(res, 0, resSize - 1);
	res[resSize] = '\0';
	return res;
}
