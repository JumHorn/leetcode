#include <stdbool.h>
#include <string.h>

bool seen(int *map, int val)
{
	for (int i = 0; i < 26; ++i)
	{
		if (map[i] == val)
			return true;
	}
	return false;
}

bool backTracking(char **words, int N, int *wordsColSize, char *result, int resultSize, int index, int carry, int *map)
{
	if (index >= resultSize)
	{
		if (carry != 0)
			return false;
		int res = map[result[0] - 'A'] > 0;
		for (int i = 0; i < N && res; ++i)
			res = res && (wordsColSize[i] == 1 || map[words[i][0] - 'A'] > 0);
		return res;
	}
	int old_carry = carry;
	for (int i = 0; i < N; ++i)
	{
		if (index >= wordsColSize[i])
			continue;
		int k = words[i][wordsColSize[i] - 1 - index] - 'A';
		if (map[k] == -1)
		{
			for (int j = 0; j < 10; ++j)
			{
				if (seen(map, j))
					continue;
				map[k] = j;
				if (backTracking(words, N, wordsColSize, result, resultSize, index, old_carry, map))
					return true;
				map[k] = -1;
			}
			return false;
		}
		carry += map[k];
	}
	int r = result[resultSize - 1 - index] - 'A';
	if (map[r] == -1)
	{
		if (seen(map, carry % 10))
			return false;
		map[r] = carry % 10;
		if (backTracking(words, N, wordsColSize, result, resultSize, index + 1, carry / 10, map))
			return true;
		map[r] = -1;
	}
	else if (map[r] == carry % 10)
	{
		if (backTracking(words, N, wordsColSize, result, resultSize, index + 1, carry / 10, map))
			return true;
	}
	return false;
}

bool isSolvable(char **words, int wordsSize, char *result)
{
	int map[26];
	int wordsColSize[wordsSize];
	for (int i = 0; i < wordsSize; ++i)
		wordsColSize[i] = strlen(words[i]);
	memset(map, -1, sizeof(map));
	return backTracking(words, wordsSize, wordsColSize, result, strlen(result), 0, 0, map);
}