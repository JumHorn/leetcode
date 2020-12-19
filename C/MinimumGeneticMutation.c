#include <stdlib.h>
#include <string.h>

//string cmp function
int cmp(const void *lhs, const void *rhs)
{
	return strcmp(*(char **)lhs, *(char **)rhs);
}

int binarySearch(char **arr, int arrSize, const char *value)
{
	int lo = 0, hi = arrSize;
	while (lo < hi)
	{
		int mi = (hi - lo) / 2 + lo;
		if (strcmp(arr[mi], value) < 0)
			lo = mi + 1;
		else
			hi = mi;
	}
	return (lo == arrSize || strcmp(arr[lo], value) != 0) ? -1 : lo;
}

int minMutation(char *start, char *end, char **bank, int bankSize)
{
	char gene[] = "ACGT";
	int seen[bankSize + 1], res = 0;
	memset(seen, 0, sizeof(seen));
	qsort(bank, bankSize, sizeof(char *), cmp);
	if (binarySearch(bank, bankSize, end) == -1)
		return -1;
	int size = bankSize + 1, front = 0, rear = 0;
	char *queue[size];
	queue[rear] = start;
	rear = (rear - 1 + size) % size; //push back
	int index = binarySearch(bank, bankSize, start);
	if (index != -1)
		seen[index] = 1;
	while (front != rear)
	{
		++res;
		int s = (front - rear + size) % size; //size
		while (--s >= 0)
		{
			char *mutation = strdup(queue[front]);
			front = (front - 1 + size) % size; //pop front
			for (int i = 0; mutation[i]; ++i)
			{
				char old = mutation[i];
				for (int j = 0; j < 4; ++j)
				{
					mutation[i] = gene[j];
					if (strcmp(mutation, end) == 0)
						return res;
					int index = binarySearch(bank, bankSize, mutation);
					if (index != -1 && seen[index] != 1)
					{
						seen[index] = 1;
						queue[rear] = bank[index];
						rear = (rear - 1 + size) % size; //push back
					}
				}
				mutation[i] = old;
			}
			free(mutation);
		}
	}
	return -1;
}