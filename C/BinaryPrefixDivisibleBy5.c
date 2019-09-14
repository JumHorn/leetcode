#include<stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* prefixesDivBy5(int* A, int ASize, int* returnSize){
	*returnSize=ASize;
	bool* p=(bool*)malloc(ASize*sizeof(bool));
	int val=0;
	for(int i=0;i<ASize;i++)
	{
		val=((val<<1)|A[i]);
		val%=5;
		p[i]=val%5==0;
	}
	return p;
}
