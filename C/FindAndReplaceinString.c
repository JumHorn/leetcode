#include <stdlib.h>
#include <string.h>

//cmp function don't consider overflow
int cmp(const void* lhs, const void* rhs)
{
	return *(int*)lhs - *(int*)rhs;
}

char* findReplaceString(char* S, int* indexes, int indexesSize, char** sources, int sourcesSize, char** targets, int targetsSize)
{
	int v[indexesSize][2];
	//sort indexes
	for (int i = 0; i < indexesSize; ++i)
	{
		v[i][0] = indexes[i];
		v[i][1] = i;
	}
	qsort(v, indexesSize, sizeof(v[0]), cmp);
	char* res = (char*)malloc(sizeof(char) * 2000);
	int index = 0, size = 0;
	for (int i = 0; i < indexesSize; ++i)
	{
		strncpy(&res[size], &S[index], v[i][0] - index);
		size += v[i][0] - index;
		index = v[i][0];
		int j = v[i][1];
		int slen = strlen(sources[j]);
		if (strncmp(&S[v[i][0]], sources[j], slen) == 0)
		{
			strcpy(&res[size], targets[j]);
			size += strlen(targets[j]);
			index += slen;
		}
	}
	strcpy(&res[size], &S[index]);
	return res;
}
