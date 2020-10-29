#include <string.h>

//cmp function don't consider overflow
int cmp(const void *lhs, const void *rhs)
{
	return strcmp((char *)lhs, (char *)rhs);
}

int uniqueMorseRepresentations(char **words, int wordsSize)
{
	char arr[wordsSize + 1][50];
	int arrSize = 0;
	char *morsecode[] = {
		".-", "-...", "-.-.", "-..", ".", "..-.", "--.",
		"....", "..", ".---", "-.-", ".-..", "--", "-.",
		"---", ".--.", "--.-", ".-.", "...", "-", "..-",
		"...-", ".--", "-..-", "-.--", "--.."};
	for (int i = 0; i < wordsSize; ++i)
	{
		int len = 0;
		for (int j = 0; words[i][j]; ++j)
			len += sprintf(&arr[arrSize][len], morsecode[words[i][j] - 'a']);
		++arrSize;
	}
	qsort(arr, arrSize, sizeof(arr[0]), cmp);
	int res = 0;
	for (int i = 1, j = 0; i <= arrSize; ++i)
	{
		if (i == arrSize || strcmp(arr[i], arr[j]) != 0)
		{
			++res;
			j = i;
		}
	}
	return res;
}