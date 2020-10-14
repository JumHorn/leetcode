#include <stdlib.h>

typedef struct
{
	int* A;
	int ASize;
	int curIndex;
	int curCount;
} RLEIterator;

RLEIterator* rLEIteratorCreate(int* A, int ASize)
{
	RLEIterator* iterator = (RLEIterator*)malloc(sizeof(RLEIterator));
	iterator->A = A;
	iterator->ASize = ASize;
	iterator->curIndex = 1;
	iterator->curCount = ASize > 0 ? A[0] : 0;
	return iterator;
}

int rLEIteratorNext(RLEIterator* obj, int n)
{
	while (obj->curIndex < obj->ASize)
	{
		if (obj->curCount >= n)
		{
			obj->curCount -= n;
			return obj->A[obj->curIndex];
		}
		n -= obj->curCount;
		obj->curIndex += 2;
		obj->curCount = obj->curIndex < obj->ASize ? obj->A[obj->curIndex - 1] : 0;
	}
	return -1;
}

void rLEIteratorFree(RLEIterator* obj)
{
	if (obj)
		free(obj);
}

/**
 * Your RLEIterator struct will be instantiated and called as such:
 * RLEIterator* obj = rLEIteratorCreate(A, ASize);
 * int param_1 = rLEIteratorNext(obj, n);
 
 * rLEIteratorFree(obj);
*/
