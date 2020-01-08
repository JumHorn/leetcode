#include <string.h>

bool arrEqual(int* arr1, int* arr2, int size)
{
	for (int i = 0; i < size; i++)
		if (arr1[i] != arr2[i])
			return false;
	return true;
}

bool checkInclusion(char* s1, char* s2)
{
	int map[26] = {0};
	int len1 = strlen(s1), len2 = strlen(s2);
	if (len1 > len2)
		return false;
	while (*s1)
		++map[*s1++ - 'a'];
	int window[26] = {0};
	for (int i = 0; i < len1; i++)
		++window[s2[i] - 'a'];
	if (arrEqual(map, window, 26))
		return true;
	for (int i = len1; i < len2; i++)
	{
		++window[s2[i] - 'a'];
		--window[s2[i - len1] - 'a'];
		if (arrEqual(map, window, 26))
			return true;
	}
	return false;
}

