#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int bitCount(int n)
{
	int res = 0;
	while (n != 0)
	{
		++res;
		n &= n - 1;
	}
	return res;
}

typedef struct
{
	int mask;
	int len;
	char* s;
	int slen;
} CombinationIterator;

CombinationIterator* combinationIteratorCreate(char* characters, int combinationLength)
{
	CombinationIterator* iterator = (CombinationIterator*)malloc(sizeof(CombinationIterator));
	iterator->s = characters;
	iterator->len = combinationLength;
	iterator->slen = strlen(characters);
	iterator->mask = (1 << iterator->slen) - 1;
	return iterator;
}

bool combinationIteratorHasNext(CombinationIterator* obj)
{
	while (obj->mask > 0 && bitCount(obj->mask) != obj->len)
		--obj->mask;
	return obj->mask != 0;
}

char* combinationIteratorNext(CombinationIterator* obj)
{
	combinationIteratorHasNext(obj);
	char* res = (char*)malloc(sizeof(char) * (obj->len + 1));
	res[obj->len] = '\0';
	for (int i = 0, j = 0; i < obj->slen; ++i)
	{
		if (obj->mask & (1 << (obj->slen - i - 1)))
			res[j++] = obj->s[i];
	}
	--obj->mask;
	return res;
}

void combinationIteratorFree(CombinationIterator* obj)
{
	if (obj)
		free(obj);
}

/**
 * Your CombinationIterator struct will be instantiated and called as such:
 * CombinationIterator* obj = combinationIteratorCreate(characters, combinationLength);
 * char * param_1 = combinationIteratorNext(obj);
 
 * bool param_2 = combinationIteratorHasNext(obj);
 
 * combinationIteratorFree(obj);
*/
