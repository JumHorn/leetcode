#include <stdlib.h>
#include <string.h>

//cmp function don't consider overflow
int cmp(const void *lhs, const void *rhs)
{
	return -strcmp((char *)lhs, (char *)rhs);
}

char *makeLargestSpecial(char *S)
{
	char strs[25][51];
	int len = strlen(S), count = 0, size = 0;
	for (int i = 0, j = 0; j < len; j++)
	{
		if (S[j] == '1')
			++count;
		else
			--count;

		if (count == 0)
		{
			char dup[51];
			memcpy(dup, &S[i + 1], sizeof(char) * (j - i - 1));
			dup[j - i - 1] = '\0';

			strs[size][0] = '1';
			strcpy(&strs[size][1], makeLargestSpecial(dup));
			strs[size][j - i] = '0';
			strs[size][j - i + 1] = '\0';

			++size;
			i = j + 1;
		}
	}
	qsort(strs, size, sizeof(strs[0]), cmp);
	static char res[51];
	res[0] = '\0'; //如果没有初始化且下面的for循环没有进入,很可能在下次strcpy时overflow
	for (int i = 0, j = 0; i < size; i++)
	{
		int n = strlen(strs[i]);
		strcpy(&res[j], strs[i]);
		j += n;
	}
	return res;
}