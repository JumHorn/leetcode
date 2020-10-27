#include <limits.h>
#include <stdlib.h>
#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

typedef struct pair
{
	char* s;
	int index;
} pair;

//cmp function don't consider overflow
int cmp(const void* lhs, const void* rhs)
{
	return strcmp(((pair*)lhs)->s, ((pair*)rhs)->s);
}

int find(pair* arr, int arrSize, char* val)
{
	int lo = 0, hi = arrSize - 1;
	while (lo < hi)
	{
		int mi = (hi - lo) / 2 + lo;
		if (strcmp(arr[mi].s, val) < 0)
			lo = mi + 1;
		else
			hi = mi;
	}
	if (strcmp(arr[lo].s, val) == 0)
		return arr[lo].index;
	return -1;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** findRestaurant(char** list1, int list1Size, char** list2, int list2Size, int* returnSize)
{
	int arrSize = list1Size;
	pair arr[list1Size];
	for (int i = 0; i < list1Size; ++i)
	{
		arr[i].s = list1[i];
		arr[i].index = i;
	}
	qsort(arr, list1Size, sizeof(pair), cmp);
	int data[max(list1Size, list2Size)], dataSize = 0;  //store index of list2 restaurant
	int indexsum = INT_MAX;
	for (int i = 0; i < list2Size; ++i)
	{
		int j = find(arr, arrSize, list2[i]);
		if (j == -1)
			continue;
		if (i + j <= indexsum)
		{
			if (i + j < indexsum)
			{
				indexsum = i + j;
				dataSize = 0;
			}
			data[dataSize++] = i;
		}
	}
	*returnSize = dataSize;
	char** res = (char**)malloc(sizeof(char*) * (*returnSize));
	for (int i = 0; i < dataSize; ++i)
		res[i] = strdup(list2[data[i]]);
	return res;
}
