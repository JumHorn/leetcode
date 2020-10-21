#include <stdlib.h>
#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

char* alphabetBoardPath(char* target)
{
	char* res = (char*)malloc(sizeof(char) * 1200);
	int i = 0, j = 0, n = 5, resSize = 0;
	for (int k = 0; target[k]; ++k)
	{
		int x = (target[k] - 'a') / n, y = (target[k] - 'a') % n;
		int len = max(0, i - x);
		memset(&res[resSize], 'U', sizeof(char) * len);
		resSize += len;
		len = max(0, y - j);
		memset(&res[resSize], 'R', sizeof(char) * len);
		resSize += len;
		len = max(0, j - y);
		memset(&res[resSize], 'L', sizeof(char) * len);
		resSize += len;
		len = max(0, x - i);
		memset(&res[resSize], 'D', sizeof(char) * len);
		resSize += len;
		res[resSize++] = '!';
		i = x;
		j = y;
	}
	res[resSize] = '\0';
	return res;
}
