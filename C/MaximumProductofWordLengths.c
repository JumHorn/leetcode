#include <string.h>

int maxProduct(char** words, int wordsSize)
{
	if (wordsSize == 0)
		return 0;
	int res = 0, mask[wordsSize];
	memset(mask, 0, sizeof(mask));
	for (int i = 0; i < wordsSize; ++i)
	{
		for (int j = 0; words[i][j]; ++j)
			mask[i] |= 1 << (words[i][j] - 'a');
		for (int j = 0; j < i; ++j)
		{
			if ((mask[i] & mask[j]) == 0)
			{
				int len = strlen(words[i]) * strlen(words[j]);
				if (res < len)
					res = len;
			}
		}
	}
	return res;
}
